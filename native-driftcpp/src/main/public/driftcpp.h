#ifndef _DRIFTCPP_H_
#define _DRIFTCPP_H_

#include <string>
#include <iostream>
#include <jni.h>

#ifndef GLuint
typedef unsigned int GLuint;
#endif

// PUBLIC API
namespace driftfx {
    
    struct Vec2i {
        int x;
        int y;
    };
    
    class TransferType {
    public:
        virtual ::std::string getId() = 0;
        virtual bool isAvailable() = 0;
    };
    
    class RenderTarget {
    };
    
    struct SwapchainConfig {
        Vec2i size;
        int imageCount;
        TransferType* transferType;
    };
    
    class Swapchain {
    public:
        virtual SwapchainConfig getConfig() = 0;
        virtual RenderTarget* acquire() = 0;
        virtual RenderTarget* tryAcquire() = 0;
        
        virtual void present(RenderTarget* image) = 0;
        
        virtual ~Swapchain() = 0;
    };
    
    
    
    class Renderer {
    public:
        virtual Swapchain* createSwapchain(SwapchainConfig config) = 0;
        virtual Vec2i getSize() = 0;
        virtual ~Renderer() = 0;
    };
    
    
    class GLRenderer {
    public:
        static GLuint getGLTextureId(RenderTarget* renderTarget);
    };
    
    
    // api entry point
    Renderer* initializeRenderer(JNIEnv* env, jobject javaRenderer);
    
    
    class StandardTransferTypes {
    public:
        static TransferType* MainMemory;
        static TransferType* IOSurface;
        static TransferType* NVDXInterop;
    };
    
    
    // initializes drift cpp
    // must be called before any other method
    // must be called from a thread which is attached to the jvm with its jni environment
    // the classLoader is used to lookup classes. in a non-osgi environment it may be the system class loader, but in osgi environment it must have access to the org.eclipse.fx.drift package
    void initialize(JNIEnv* env, jobject classLoader);
    
    // releases drift cpp resources
    void dispose(JNIEnv* env);
    
}


// INTERNAL API
namespace internal {
    
    
    class JNI {
    public:
        static void init(JNIEnv* env, jobject classLoader);
        static void dispose(JNIEnv* env);
        
    private:
        static jobject classLoader;
        
        // Class
    private:
        static jclass cClass;
        static jmethodID mClassForName;
    public:
        static jclass getClass(JNIEnv* env, const char* name);
        
        // Vec2i
    private:
        static jclass cVec2i;
        static jmethodID mVec2iConstructor;
        static jfieldID fVec2iX;
        static jfieldID fVec2iY;
    public:
        static driftfx::Vec2i convertVec2i(JNIEnv* env, jobject vec2i);
        static jobject convertVec2i(JNIEnv* env, driftfx::Vec2i vec2i);
        
        // SwapchainConfig
    private:
        static jclass cSwapchainConfig;
        static jmethodID mSwapchainConfigConstructor;
        static jfieldID fSwapchainConfigSize;
        static jfieldID fSwapchainConfigImageCount;
        static jfieldID fSwapchainConfigPresentationMode;
        static jfieldID fSwapchainConfigTransferType;
    public:
        static jobject convertSwapchainConfig(JNIEnv* env, driftfx::SwapchainConfig swapchainConfig);
        static driftfx::SwapchainConfig convertSwapchainConfig(JNIEnv* env, jobject swapchainConfig);
        // Swapchain
    private:
        static jmethodID mSwapchainAcquire;
        static jmethodID mSwapchainTryAcquire;
        static jmethodID mSwapchainPresent;
        static jmethodID mSwapchainDispose;
        static jmethodID mSwapchainGetConfig;
    public:
        static jobject callSwapchainAcquire(JNIEnv* env, jobject swapchain);
        static jobject callSwapchainTryAcquire(JNIEnv* env, jobject swapchain);
        static void callSwapchainPresent(JNIEnv* env, jobject swapchain, jobject renderTarget);
        static void callSwapchainDispose(JNIEnv* env, jobject swapchain);
        static jobject callSwapchainGetConfig(JNIEnv* env, jobject swapchain);
        // Renderer
    private:
        static jmethodID mRendererGetSize;
        static jmethodID mRendererCreateSwapchain;
    public:
        static jobject callRendererGetSize(JNIEnv* env, jobject renderer);
        static jobject callRendererCreateSwapchain(JNIEnv* env, jobject renderer, jobject swapchainConfig);
        
        // GLRenderer
    private:
        static jclass cGLRenderer;
        static jmethodID mGLRendererGetGLTextureId;
    public:
        static jint callGLRendererGetGLTextureId(JNIEnv* env, jobject renderTarget);
    };
    
    
    class JNIObject {
    protected:
        JNIEnv* env;
        jobject javaInstance;
    public:
        jobject getJavaInstance();
        JNIEnv* getJavaEnv();
    };
    
    
    class RendererImpl : public driftfx::Renderer, public JNIObject {
        
    public:
        RendererImpl(JNIEnv* _env, jobject _javaInstance);
        
        driftfx::Swapchain* createSwapchain(driftfx::SwapchainConfig config);
        
        driftfx::Vec2i getSize();
        
    };
    
    class SwapchainImpl : public driftfx::Swapchain, public JNIObject {
        
    public:
        SwapchainImpl(JNIEnv* _env, jobject _javaInstance);
        
        driftfx::SwapchainConfig getConfig();
        driftfx::RenderTarget* acquire();
        driftfx::RenderTarget* tryAcquire();
        void present(driftfx::RenderTarget* image);
        
        ~SwapchainImpl();
        
    };
    
    class RenderTargetImpl : public driftfx::RenderTarget, public JNIObject {
        
    public:
        RenderTargetImpl(JNIEnv* _env, jobject _javaInstance);
        
    };
    
    class TransferTypeImpl : public driftfx::TransferType, public JNIObject {
        
    public:
        TransferTypeImpl(JNIEnv* _env, jobject _javaInstance);
        ::std::string getId();
        bool isAvailable();
        
    };
    
    
    
    
}



jobject internal::JNI::classLoader;

// Class
jclass internal::JNI::cClass;
jmethodID internal::JNI::mClassForName;

// Vec2i
jclass internal::JNI::cVec2i;
jmethodID internal::JNI::mVec2iConstructor;
jfieldID internal::JNI::fVec2iX;
jfieldID internal::JNI::fVec2iY;

// SwapchainConfig
jclass internal::JNI::cSwapchainConfig;
jmethodID internal::JNI::mSwapchainConfigConstructor;
jfieldID internal::JNI::fSwapchainConfigSize;
jfieldID internal::JNI::fSwapchainConfigImageCount;
jfieldID internal::JNI::fSwapchainConfigPresentationMode;
jfieldID internal::JNI::fSwapchainConfigTransferType;

// Swapchain
jmethodID internal::JNI::mSwapchainAcquire;
jmethodID internal::JNI::mSwapchainTryAcquire;
jmethodID internal::JNI::mSwapchainPresent;
jmethodID internal::JNI::mSwapchainDispose;
jmethodID internal::JNI::mSwapchainGetConfig;

// Renderer
jmethodID internal::JNI::mRendererGetSize;
jmethodID internal::JNI::mRendererCreateSwapchain;

// GLRenderer
jclass internal::JNI::cGLRenderer;
jmethodID internal::JNI::mGLRendererGetGLTextureId;


jclass internal::JNI::getClass(JNIEnv* env, const char* name) {
    jstring className = env->NewStringUTF(name);
    jclass result = (jclass) env->CallStaticObjectMethod(cClass, mClassForName, className, JNI_FALSE, classLoader);
    env->DeleteLocalRef(className);
    return result;
}

void internal::JNI::init(JNIEnv* env, jobject _classLoader) {
    classLoader = env->NewGlobalRef(_classLoader);
    // Class
    cClass = env->FindClass("java/lang/Class");
    cClass = (jclass)env->NewGlobalRef(cClass);
    mClassForName = env->GetStaticMethodID(cClass, "forName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;");
    // Vec2i
    cVec2i = getClass(env, "org.eclipse.fx.drift.Vec2i"); //env->FindClass("org/eclipse/fx/drift/Vec2i");
    cVec2i = (jclass)env->NewGlobalRef(cVec2i);
    mVec2iConstructor = env->GetMethodID(cVec2i, "<init>", "(II)V");
    fVec2iX = env->GetFieldID(cVec2i, "x", "I");
    fVec2iY = env->GetFieldID(cVec2i, "y", "I");
    // SwapchainConfig
    cSwapchainConfig = getClass(env, "org.eclipse.fx.drift.SwapchainConfig"); //env->FindClass("org/eclipse/fx/drift/SwapchainConfig");
    cSwapchainConfig = (jclass)env->NewGlobalRef(cSwapchainConfig);
    mSwapchainConfigConstructor = env->GetMethodID(cSwapchainConfig, "<init>", "(Lorg/eclipse/fx/drift/Vec2i;ILorg/eclipse/fx/drift/PresentationMode;Lorg/eclipse/fx/drift/TransferType;)V");
    fSwapchainConfigSize = env->GetFieldID(cSwapchainConfig, "size", "Lorg/eclipse/fx/drift/Vec2i;");
    fSwapchainConfigImageCount = env->GetFieldID(cSwapchainConfig, "imageCount", "I");
    fSwapchainConfigPresentationMode = env->GetFieldID(cSwapchainConfig, "presentationMode", "Lorg/eclipse/fx/drift/PresentationMode;");
    fSwapchainConfigTransferType = env->GetFieldID(cSwapchainConfig, "transferType", "Lorg/eclipse/fx/drift/TransferType;");
    // Swapchain
    jclass cSwapchain = getClass(env, "org.eclipse.fx.drift.Swapchain"); //env->FindClass("org/eclipse/fx/drift/Swapchain");
    mSwapchainAcquire = env->GetMethodID(cSwapchain, "acquire", "()Lorg/eclipse/fx/drift/RenderTarget;");
    // mSwapchainTryAcquire // TODO generics!?
    mSwapchainPresent = env->GetMethodID(cSwapchain, "present", "(Lorg/eclipse/fx/drift/RenderTarget;)V");
    mSwapchainDispose = env->GetMethodID(cSwapchain, "dispose", "()V");
    mSwapchainGetConfig = env->GetMethodID(cSwapchain, "getConfig", "()Lorg/eclipse/fx/drift/SwapchainConfig;");
    // Renderer
    jclass cRenderer = getClass(env, "org.eclipse.fx.drift.Renderer"); //env->FindClass("org/eclipse/fx/drift/Renderer");
    mRendererGetSize = env->GetMethodID(cRenderer, "getSize", "()Lorg/eclipse/fx/drift/Vec2i;");
    mRendererCreateSwapchain = env->GetMethodID(cRenderer, "createSwapchain", "(Lorg/eclipse/fx/drift/SwapchainConfig;)Lorg/eclipse/fx/drift/Swapchain;");
    // GLRenderer
    cGLRenderer = getClass(env, "org.eclipse.fx.drift.GLRenderer"); //env->FindClass("org/eclipse/fx/drift/GLRenderer");
    cGLRenderer = (jclass)env->NewGlobalRef(cGLRenderer);
    mGLRendererGetGLTextureId = env->GetStaticMethodID(cGLRenderer, "getGLTextureId", "(Lorg/eclipse/fx/drift/RenderTarget;)I");
    
    jclass cStandardTransferTypes = getClass(env, "org.eclipse.fx.drift.StandardTransferTypes"); //env->FindClass("org/eclipse/fx/drift/StandardTransferTypes");
    jfieldID fStandardTransferTypesMainMemory = env->GetStaticFieldID(cStandardTransferTypes, "MainMemory", "Lorg/eclipse/fx/drift/TransferType;");
    jfieldID fStandardTransferTypesIOSurface = env->GetStaticFieldID(cStandardTransferTypes, "IOSurface", "Lorg/eclipse/fx/drift/TransferType;");
    jfieldID fStandardTransferTypesNVDXInterop = env->GetStaticFieldID(cStandardTransferTypes, "NVDXInterop", "Lorg/eclipse/fx/drift/TransferType;");
    
    jobject mainMemory = env->GetStaticObjectField(cStandardTransferTypes, fStandardTransferTypesMainMemory);
    jobject ioSurface = env->GetStaticObjectField(cStandardTransferTypes, fStandardTransferTypesIOSurface);
    jobject nvdxInterop = env->GetStaticObjectField(cStandardTransferTypes, fStandardTransferTypesNVDXInterop);
    
    mainMemory = env->NewGlobalRef(mainMemory);
    ioSurface = env->NewGlobalRef(ioSurface);
    nvdxInterop = env->NewGlobalRef(nvdxInterop);
    
    driftfx::StandardTransferTypes::MainMemory = new TransferTypeImpl(env, mainMemory);
    driftfx::StandardTransferTypes::IOSurface = new TransferTypeImpl(env, ioSurface);
    driftfx::StandardTransferTypes::NVDXInterop = new TransferTypeImpl(env, nvdxInterop);
}

void internal::JNI::dispose(JNIEnv* env) {
    env->DeleteGlobalRef(classLoader);
    
    // Class
    env->DeleteGlobalRef(cClass);
    
    // Vec2i
    env->DeleteGlobalRef(cVec2i);
    // SwapchainConfig
    env->DeleteGlobalRef(cSwapchainConfig);
    // Swapchain
    // (nothing to dispose)
    // Renderer
    // (nothing to dispose)
    // GLRenderer
    env->DeleteGlobalRef(cGLRenderer);
}


driftfx::Vec2i internal::JNI::convertVec2i(JNIEnv* env, jobject vec2i) {
    jint x = env->GetIntField(vec2i, fVec2iX);
    jint y = env->GetIntField(vec2i, fVec2iY);
    driftfx::Vec2i result;
    result.x = x;
    result.y = y;
    return result;
}

jobject internal::JNI::convertVec2i(JNIEnv* env, driftfx::Vec2i vec2i) {
    jint x = vec2i.x;
    jint y = vec2i.y;
    return env->NewObject(cVec2i, mVec2iConstructor, x, y);
}

jobject internal::JNI::convertSwapchainConfig(JNIEnv* env, driftfx::SwapchainConfig swapchainConfig) {
    jobject size = convertVec2i(env, swapchainConfig.size);
    jint imageCount = swapchainConfig.imageCount;
    jobject presentationMode = nullptr; // TODO setup presentation mode
    TransferTypeImpl* impl = (TransferTypeImpl*) swapchainConfig.transferType;
    jobject transferType = impl->getJavaInstance();
    return env->NewObject(cSwapchainConfig, mSwapchainConfigConstructor, size, imageCount, presentationMode, transferType);
}

driftfx::SwapchainConfig internal::JNI::convertSwapchainConfig(JNIEnv* env, jobject swapchainConfig) {
    driftfx::SwapchainConfig config;
    
    jobject size = env->GetObjectField(swapchainConfig, fSwapchainConfigSize);
    config.size = convertVec2i(env, size);
    config.imageCount = env->GetIntField(swapchainConfig, fSwapchainConfigImageCount);
    jobject tt = env->GetObjectField(swapchainConfig, fSwapchainConfigTransferType);
    // TODO map transfer type
    config.transferType = nullptr;
    return config;
}

jobject internal::JNI::callSwapchainAcquire(JNIEnv* env, jobject swapchain) {
    return env->CallObjectMethod(swapchain, mSwapchainAcquire);
}

jobject internal::JNI::callSwapchainTryAcquire(JNIEnv* env, jobject swapchain) {
    // TODO
    return nullptr;
}

void internal::JNI::callSwapchainPresent(JNIEnv* env, jobject swapchain, jobject renderTarget) {
    env->CallVoidMethod(swapchain, mSwapchainPresent, renderTarget);
}

void internal::JNI::callSwapchainDispose(JNIEnv* env, jobject swapchain) {
    env->CallVoidMethod(swapchain, mSwapchainDispose);
}

jobject internal::JNI::callSwapchainGetConfig(JNIEnv* env, jobject swapchain) {
    return env->CallObjectMethod(swapchain, mSwapchainGetConfig);
}



jobject internal::JNI::callRendererGetSize(JNIEnv* env, jobject renderer) {
    return env->CallObjectMethod(renderer, mRendererGetSize);
}

jobject internal::JNI::callRendererCreateSwapchain(JNIEnv* env, jobject renderer, jobject swapchainConfig) {
    return env->CallObjectMethod(renderer, mRendererCreateSwapchain, swapchainConfig);
}

jint internal::JNI::callGLRendererGetGLTextureId(JNIEnv* env, jobject renderTarget) {
    return env->CallStaticIntMethod(cGLRenderer, mGLRendererGetGLTextureId, renderTarget);
}

driftfx::Renderer::~Renderer() {
}




internal::RendererImpl::RendererImpl(JNIEnv* _env, jobject javaRenderer) {
    this->env = _env;
    this->javaInstance = javaRenderer;
}

driftfx::Vec2i internal::RendererImpl::getSize() {
    jobject javaSize = internal::JNI::callRendererGetSize(env, javaInstance);
    return internal::JNI::convertVec2i(env, javaSize);
}


driftfx::Swapchain* internal::RendererImpl::createSwapchain(driftfx::SwapchainConfig config) {
    jobject javaSwapchain = internal::JNI::callRendererCreateSwapchain(env, javaInstance, internal::JNI::convertSwapchainConfig(env, config));
    return new internal::SwapchainImpl(env, javaSwapchain);
}



internal::SwapchainImpl::SwapchainImpl(JNIEnv* _env, jobject _javaInstance) {
    this->env = _env;
    this->javaInstance = _javaInstance;
}

void internal::SwapchainImpl::present(driftfx::RenderTarget* target) {
    internal::RenderTargetImpl* internalTarget = (internal::RenderTargetImpl*) target;
    internal::JNI::callSwapchainPresent(env, javaInstance, internalTarget->getJavaInstance());
}

driftfx::RenderTarget* internal::SwapchainImpl::acquire() {
    jobject renderTarget = internal::JNI::callSwapchainAcquire(env, javaInstance);
    return new RenderTargetImpl(env, renderTarget);
}

driftfx::RenderTarget* internal::SwapchainImpl::tryAcquire() {
    jobject renderTarget = internal::JNI::callSwapchainTryAcquire(env, javaInstance);
    return nullptr; // TODO optional<rendertarget>
}

driftfx::Swapchain::~Swapchain() {
}
internal::SwapchainImpl::~SwapchainImpl() {
    internal::JNI::callSwapchainDispose(env, javaInstance);
}

driftfx::SwapchainConfig internal::SwapchainImpl::getConfig() {
    jobject config = internal::JNI::callSwapchainGetConfig(env, javaInstance);
    return internal::JNI::convertSwapchainConfig(env, config);
}

internal::RenderTargetImpl::RenderTargetImpl(JNIEnv* _env, jobject _javaInstance) {
    this->env = _env;
    this->javaInstance = _javaInstance;
}

internal::TransferTypeImpl::TransferTypeImpl(JNIEnv* _env, jobject _javaInstance) {
    env = _env;
    javaInstance = _javaInstance;
}


::std::string internal::TransferTypeImpl::getId() {
    return "TODO!";
}

bool internal::TransferTypeImpl::isAvailable() {
    return false;
}

jobject internal::JNIObject::getJavaInstance() {
    return javaInstance;
}
JNIEnv* internal::JNIObject::getJavaEnv() {
    return env;
}


GLuint driftfx::GLRenderer::getGLTextureId(driftfx::RenderTarget* renderTarget) {
    
    internal::RenderTargetImpl* targetImpl = (internal::RenderTargetImpl*) renderTarget;
    
    return (GLuint) internal::JNI::callGLRendererGetGLTextureId(targetImpl->getJavaEnv(), targetImpl->getJavaInstance());
}


driftfx::Renderer* driftfx::initializeRenderer(JNIEnv* env, jobject javaRenderer) {
    return new internal::RendererImpl(env, javaRenderer);
}




driftfx::TransferType* driftfx::StandardTransferTypes::MainMemory = nullptr;
driftfx::TransferType* driftfx::StandardTransferTypes::IOSurface = nullptr;
driftfx::TransferType* driftfx::StandardTransferTypes::NVDXInterop = nullptr;


void driftfx::initialize(JNIEnv* env, jobject classLoader) {
    internal::JNI::init(env, classLoader);
}

void driftfx::dispose(JNIEnv* env) {
    internal::JNI::dispose(env);
}

#endif // _DRIFTCPP_H_
