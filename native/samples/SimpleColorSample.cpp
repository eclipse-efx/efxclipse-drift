
#include <jni.h>

#include <sstream>
#include <string>
#include <iostream>
#include <thread>
#include <mutex>


#include <GL/glew.h>

#include <minctx.h>

#include <DriftFX/driftcpp.h>


namespace SimpleColorSample {

	struct RendererInstance {
		JavaVM* vm;
		jobject javaRenderer;
		bool running;
		std::mutex mutex;
		std::thread thread;

		minctx::Context* glContext;

		driftfx::Renderer* renderer;
		driftfx::Swapchain* swapchain;


		GLuint fb;


		int widths[10];
		int heights[10];
		int idx = 0;
	};


	void beforeLoop(RendererInstance* instance) {

		instance->glContext = minctx::CreateContext(nullptr, 4, 2);

		std::cout << "glContext = " << instance->glContext << std::endl;

		bool res = minctx::MakeContextCurrent(instance->glContext);
		std::cout << " context is set: " << res << std::endl;
		std::cout << "my context = " << minctx::IsContextCurrent(instance->glContext) << std::endl;

		glGenFramebuffers(1, &instance->fb);
	}

	void afterLoop(RendererInstance* instance) {

		glDeleteFramebuffers(1, &instance->fb);

		minctx::DestroyContext(instance->glContext);

	}

	void recreateSwapchain(RendererInstance* instance) {
		if (instance->swapchain != nullptr) {
			delete instance->swapchain;
			instance->swapchain = nullptr;
		}

		driftfx::SwapchainConfig cfg;
		cfg.imageCount = 2;
		cfg.size = instance->renderer->getSize();
		std::cout << " using size " << cfg.size.x << " / " << cfg.size.y << std::endl;
		cfg.transferType = driftfx::StandardTransferTypes::NVDXInterop;

		instance->swapchain = instance->renderer->createSwapchain(cfg);
	}

	bool isSameSize(driftfx::Renderer* renderer, driftfx::Swapchain* swapchain) {
		auto cfg = swapchain->getConfig();
		auto surface = renderer->getSize();
		return surface.x == cfg.size.x && surface.y == cfg.size.y;
	}


	// uses the last 10 frames size data to prevent permanent recreation of a swapchain during resizing
	bool needsResize(RendererInstance* instance) {
		auto size = instance->renderer->getSize();

		instance->widths[instance->idx] = size.x;
		instance->heights[instance->idx] = size.y;

		instance->idx++;
		instance->idx = instance->idx % 10;

		bool noChange = true;
		for (int i = 0; i < 10; i++) {
			if (size.x != instance->widths[i]) {
				noChange = false;
				break;
			}
			if (size.y != instance->heights[i]) {
				noChange = false;
				break;
			}
		}

		if (noChange) {
			auto cfg = instance->swapchain->getConfig();
			if (cfg.size.x != size.x || cfg.size.y != size.y) {
				return true;
			}
		}

		return false;
	}


	void checkFb() {
		GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
		if (status != GL_FRAMEBUFFER_COMPLETE) {
			std::cout << "Framebuffer incomplete!" << std::endl;

			switch (status) {
			case GL_FRAMEBUFFER_COMPLETE: break;
			case GL_FRAMEBUFFER_UNDEFINED: std::cout << "GL_FRAMEBUFFER_UNDEFINED" << std::endl; break;
			case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT: std::cout << "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT" << std::endl; break;
			case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: std::cout << "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT" << std::endl; break;
			case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER: std::cout << "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER" << std::endl; break;
			case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER: std::cout << "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER" << std::endl; break;
			case GL_FRAMEBUFFER_UNSUPPORTED: std::cout << "GL_FRAMEBUFFER_UNSUPPORTED" << std::endl; break;
			case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: std::cout << "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE" << std::endl; break;
			case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS: std::cout << "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS" << std::endl; break;
			default: std::cout << "Unknown framebuffer issue " << status << std::endl; break;
			}

		}
	}

	void onLoop(RendererInstance* instance) {
		//std::cout << "onLoop" << std::endl;

		if (instance->swapchain == nullptr || needsResize(instance)) {
			recreateSwapchain(instance);
		}

		driftfx::RenderTarget* target = instance->swapchain->acquire();


		glBindFramebuffer(GL_FRAMEBUFFER, instance->fb);
		glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, driftfx::GLRenderer::getGLTextureId(target), 0);

		checkFb();

		glClearColor(0.506, 0.588, 0.561, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		// three color check rects
		glEnable(GL_SCISSOR_TEST);
		glScissor(10, 10, 50, 50);
		glViewport(10, 10, 50, 50);
		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glScissor(70, 10, 50, 50);
		glViewport(10, 10, 50, 50);
		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glScissor(130, 10, 50, 50);
		glViewport(10, 10, 50, 50);
		glClearColor(0, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glDisable(GL_SCISSOR_TEST);


		glFlush();

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		instance->swapchain->present(target);
	}

	void mainLoop(RendererInstance* instance) {
		std::cout << "Starting mainLoop for " << instance << std::endl;

		JNIEnv* env;

		// first we need to attach the thread to the jvm
		jint stat = instance->vm->GetEnv((void**)&env, JNI_VERSION_1_6);
		if (stat == JNI_EDETACHED) {
			// attach
			std::ostringstream os;
			os << "C++ Thread id: " << std::this_thread::get_id();
			JavaVMAttachArgs args;
			args.version = JNI_VERSION_1_6;
			// copy the string
			auto strSize = os.str().size() + 1;
			char* buf = new char[strSize];
			memcpy(buf, os.str().c_str(), strSize);
			args.name = buf;
			args.group = NULL;
			jint attachResult = instance->vm->AttachCurrentThreadAsDaemon((void**)&env, &args);
			if (attachResult != JNI_OK) {
				std::cerr << "Could not attach thread to jvm!!" << std::endl;
			}
		}


		instance->renderer = driftfx::initializeRenderer(env, instance->javaRenderer);

		beforeLoop(instance);

		while (instance->running) {


			onLoop(instance);

			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}

		afterLoop(instance);

		delete instance->renderer;

		// we need to detach the thread from the jvm
		if (stat == JNI_EDETACHED) {
			// if it was not attached by us we wont detach it!
			jint detachResult = instance->vm->DetachCurrentThread();
			if (detachResult != JNI_OK) {
				std::cerr << "Could not detach thread from jvm!!!" << std::endl;
			}
		}

		std::cout << "Exiting mainLoop for " << instance << std::endl;
	}


	void start(RendererInstance* instance) {
		instance->running = true;
		instance->thread = std::thread(mainLoop, instance);
	}

	void stop(RendererInstance* instance) {
		instance->mutex.lock();
		instance->running = false;
		instance->mutex.unlock();
		instance->thread.join();
	}
}


extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_samples_cpp_SimpleColorSample_nInitialize(JNIEnv * env, jclass cls, jobject _renderer) {
	JavaVM* vm;
	env->GetJavaVM(&vm);

	auto instance = new SimpleColorSample::RendererInstance();
	instance->vm = vm;
	instance->javaRenderer = env->NewGlobalRef(_renderer);

	return (jlong) instance;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_samples_cpp_SimpleColorSample_nDispose(JNIEnv * env, jclass cls, jlong _instance) {
	auto instance = (SimpleColorSample::RendererInstance*) _instance;

	std::cout << "nDispose" << std::endl;

	delete instance;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_samples_cpp_SimpleColorSample_nStart(JNIEnv * env, jclass cls, jlong _instance) {
	auto instance = (SimpleColorSample::RendererInstance*)_instance;

	std::cout << "nStart" << std::endl;

	SimpleColorSample::start(instance);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_samples_cpp_SimpleColorSample_nStop(JNIEnv * env, jclass cls, jlong _instance) {
	auto instance = (SimpleColorSample::RendererInstance*)_instance;

	SimpleColorSample::stop(instance);
	std::cout << "nStop" << std::endl;
}