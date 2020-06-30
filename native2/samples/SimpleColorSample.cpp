
#include <jni.h>

#include <sstream>
#include <string>
#include <iostream>
#include <thread>
#include <mutex>


#include <GL/glew.h>

#include <minctx.h>

#include <DriftFX/driftcpp.h>


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

void onLoop(RendererInstance* instance) {
	//std::cout << "onLoop" << std::endl;

		// ensure context =? 
	std::cout << "my instant context = " << minctx::IsContextCurrent(instance->glContext) << std::endl;
	// GL CONTEXT IS CURRENT

	if (instance->swapchain == nullptr) {

		// dummy fix
		driftfx::SwapchainConfig dummy;
		dummy.imageCount = 2;
		dummy.size.x = 100;
		dummy.size.y = 100;
		dummy.transferType = driftfx::StandardTransferTypes::MainMemory;
		driftfx::Swapchain* dummyChain = instance->renderer->createSwapchain(dummy);
		std::cout << "ctx after dummy = " << minctx::IsContextCurrent(instance->glContext) << std::endl;

		bool res = minctx::MakeContextCurrent(instance->glContext);
		std::cout << " [HOTFIX] context is set: " << res << std::endl;

		delete dummyChain;




		std::cout << "onLoop (re-)init swapchain" << std::endl;
		std::cout << "marker0" << std::endl;
		driftfx::SwapchainConfig cfg;
		std::cout << "marker1" << std::endl;
		cfg.imageCount = 2;
		std::cout << "marker2 (renderer = " << instance->renderer << ")" << std::endl;
		cfg.size = instance->renderer->getSize();
		std::cout << "marker3" << std::endl;
		std::cout << "using size " << cfg.size.x << " / " << cfg.size.y << std::endl;
		cfg.transferType = driftfx::StandardTransferTypes::NVDXInterop;


		instance->swapchain = instance->renderer->createSwapchain(cfg);
	}
	std::cout << "my and here context = " << minctx::IsContextCurrent(instance->glContext) << std::endl;

	// BIG TODO:
	// Initialze of drift changes the gl context on createSwapchain! -> FIX THIS
	bool res = minctx::MakeContextCurrent(instance->glContext);
	std::cout << " [HOTSPOT] context is set: " << res << std::endl;

	driftfx::RenderTarget* target = instance->swapchain->acquire();


	// ensure context =? 
	std::cout << "my framebuffer = " << instance->fb << std::endl;
	std::cout << "my context = " << minctx::IsContextCurrent(instance->glContext) << std::endl;
	// GL CONTEXT IS _NOT_ CURRENT



	// next
	GLboolean really = glIsTexture(target->getGLTexture());
	std::cout << "it is " << (bool)really << " a texture." << std::endl;

	glBindFramebuffer(GL_FRAMEBUFFER, instance->fb);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, target->getGLTexture(), 0);

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


//	Renderer* renderer;

//	SwapChain* swapChain = renderer->createSwapChain();

//	RenderTarget* renderTarget = swapChain->acquire();



//	swapChain->present(renderTarget);

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



extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_samples_cpp_SimpleColorSample_nInitialize(JNIEnv * env, jclass cls, jobject _renderer) {
	JavaVM* vm;
	env->GetJavaVM(&vm);

	RendererInstance* instance = new RendererInstance();
	instance->vm = vm;
	instance->javaRenderer = env->NewGlobalRef(_renderer);

	std::cout << "nInitialize" << std::endl;

//	driftfx::Renderer* tmpRenderer = driftfx::initializeRenderer(env, instance->javaRenderer);
//	std::cout << "tmpRenderer: " << tmpRenderer << std::endl;

//	driftfx::Vec2i size = tmpRenderer->getSize();
//	std::cout << "tmpRenderer->getSize(): " << size.x << " / " << size.y << std::endl;

//	delete tmpRenderer;


	std::cout << "tmp done." << std::endl;


	return (jlong) instance;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_samples_cpp_SimpleColorSample_nDispose(JNIEnv * env, jclass cls, jlong _instance) {
	JavaVM* vm;

	RendererInstance* instance = (RendererInstance*) _instance;

	std::cout << "nDispose" << std::endl;

	delete instance;
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_samples_cpp_SimpleColorSample_nStart(JNIEnv * env, jclass cls, jlong _instance) {
	JavaVM* vm;
	RendererInstance* instance = (RendererInstance*)_instance;

	std::cout << "nStart" << std::endl;

	start(instance);
}

extern "C" JNIEXPORT void JNICALL Java_org_eclipse_fx_drift_samples_cpp_SimpleColorSample_nStop(JNIEnv * env, jclass cls, jlong _instance) {
	JavaVM* vm;
	RendererInstance* instance = (RendererInstance*)_instance;

	stop(instance);
	std::cout << "nStop" << std::endl;
}