#include <driftcpp.h>

#include <string>
#include <map>

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

        // TransferType
    private:
        static jfieldID fTransferTypeId;
        static jmethodID mTransferTypeIsAvailable;
    public:
        static jstring getTransferTypeId(JNIEnv* env, jobject transferType);
        static jboolean callTransferTypeIsAvailable(JNIEnv* env, jobject transferType);

        // String
    private:
        static jmethodID mStringGetBytes;
    public:
        static jbyteArray callStringGetBytes(JNIEnv* env, jstring str);

        static std::string convert(JNIEnv* env, jstring str);


    private:
        static std::map<std::string, driftfx::TransferType*> transferTypes;

    public:
        static driftfx::TransferType* getTransferType(JNIEnv* env, jobject transferType);
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
        
    private:
        driftfx::SwapchainConfig config;

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
        
    private:
        ::std::string id;
    public:
        TransferTypeImpl(JNIEnv* _env, jobject _javaInstance);
        ::std::string getId();
        bool isAvailable();

        

    };
    
    
    
}

std::map<std::string, driftfx::TransferType*> internal::JNI::transferTypes;

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

// TransferType
jfieldID internal::JNI::fTransferTypeId;
jmethodID internal::JNI::mTransferTypeIsAvailable;

// String
jmethodID internal::JNI::mStringGetBytes;

jclass internal::JNI::getClass(JNIEnv* env, const char* name) {
    jstring className = env->NewStringUTF(name);
    jclass result = (jclass) env->CallStaticObjectMethod(cClass, mClassForName, className, JNI_FALSE, classLoader);
    env->DeleteLocalRef(className);
    return result;
}

void dbgClass(const char* name, jclass clazz) {
    std::cout << " * " << name << ": " << clazz << std::endl;
}
void dbgField(const char* name, jfieldID field) {
    std::cout << "   - " << name << ": " << field << std::endl;
}
void dbgMethod(const char* name, jmethodID method) {
    std::cout << "   - " << name << ": " << method << std::endl;
}

void internal::JNI::init(JNIEnv* env, jobject _classLoader) {
    classLoader = env->NewGlobalRef(_classLoader);
    // Class
    cClass = env->FindClass("java/lang/Class");
    cClass = (jclass)env->NewGlobalRef(cClass);
    mClassForName = env->GetStaticMethodID(cClass, "forName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;");

    dbgClass("Class", cClass);
    dbgMethod("forName", mClassForName);

    // Vec2i
    cVec2i = getClass(env, "org.eclipse.fx.drift.Vec2i"); //env->FindClass("org/eclipse/fx/drift/Vec2i");
    cVec2i = (jclass)env->NewGlobalRef(cVec2i);
    mVec2iConstructor = env->GetMethodID(cVec2i, "<init>", "(II)V");
    fVec2iX = env->GetFieldID(cVec2i, "x", "I");
    fVec2iY = env->GetFieldID(cVec2i, "y", "I");

    dbgClass("Vec2i", cVec2i);
    dbgMethod("Vec2i(int, int)", mVec2iConstructor);
    dbgField("x", fVec2iX);
    dbgField("y", fVec2iY);

    // SwapchainConfig
    cSwapchainConfig = getClass(env, "org.eclipse.fx.drift.SwapchainConfig"); //env->FindClass("org/eclipse/fx/drift/SwapchainConfig");
    cSwapchainConfig = (jclass)env->NewGlobalRef(cSwapchainConfig);
    mSwapchainConfigConstructor = env->GetMethodID(cSwapchainConfig, "<init>", "(Lorg/eclipse/fx/drift/Vec2i;ILorg/eclipse/fx/drift/PresentationMode;Lorg/eclipse/fx/drift/TransferType;)V");
    fSwapchainConfigSize = env->GetFieldID(cSwapchainConfig, "size", "Lorg/eclipse/fx/drift/Vec2i;");
    fSwapchainConfigImageCount = env->GetFieldID(cSwapchainConfig, "imageCount", "I");
    fSwapchainConfigPresentationMode = env->GetFieldID(cSwapchainConfig, "presentationMode", "Lorg/eclipse/fx/drift/PresentationMode;");
    fSwapchainConfigTransferType = env->GetFieldID(cSwapchainConfig, "transferType", "Lorg/eclipse/fx/drift/TransferType;");

    dbgClass("SwapchainConfig", cSwapchainConfig);
    dbgMethod("SwapchainConfig(Vec2i, int, PresentationMode, TransferType)", mSwapchainConfigConstructor);
    dbgField("size", fSwapchainConfigSize);
    dbgField("imageCount", fSwapchainConfigImageCount);
    dbgField("presentationMode", fSwapchainConfigPresentationMode);
    dbgField("transferType", fSwapchainConfigTransferType);

    // Swapchain
    jclass cSwapchain = getClass(env, "org.eclipse.fx.drift.Swapchain"); //env->FindClass("org/eclipse/fx/drift/Swapchain");
    mSwapchainAcquire = env->GetMethodID(cSwapchain, "acquire", "()Lorg/eclipse/fx/drift/RenderTarget;");

    dbgClass("Swapchain", cSwapchain);
    dbgMethod("acquire()", mSwapchainAcquire);

    // mSwapchainTryAcquire // TODO generics!?
    mSwapchainPresent = env->GetMethodID(cSwapchain, "present", "(Lorg/eclipse/fx/drift/RenderTarget;)V");
    mSwapchainDispose = env->GetMethodID(cSwapchain, "dispose", "()V");
    mSwapchainGetConfig = env->GetMethodID(cSwapchain, "getConfig", "()Lorg/eclipse/fx/drift/SwapchainConfig;");

    dbgMethod("present(RenderTarget)", mSwapchainPresent);
    dbgMethod("dispose()", mSwapchainDispose);
    dbgMethod("getConfig()", mSwapchainGetConfig);

    // Renderer
    jclass cRenderer = getClass(env, "org.eclipse.fx.drift.Renderer"); //env->FindClass("org/eclipse/fx/drift/Renderer");
    mRendererGetSize = env->GetMethodID(cRenderer, "getSize", "()Lorg/eclipse/fx/drift/Vec2i;");
    mRendererCreateSwapchain = env->GetMethodID(cRenderer, "createSwapchain", "(Lorg/eclipse/fx/drift/SwapchainConfig;)Lorg/eclipse/fx/drift/Swapchain;");
    // GLRenderer
    cGLRenderer = getClass(env, "org.eclipse.fx.drift.GLRenderer"); //env->FindClass("org/eclipse/fx/drift/GLRenderer");
    cGLRenderer = (jclass)env->NewGlobalRef(cGLRenderer);
    mGLRendererGetGLTextureId = env->GetStaticMethodID(cGLRenderer, "getGLTextureId", "(Lorg/eclipse/fx/drift/RenderTarget;)I");
    
    dbgClass("Renderer", cRenderer);
    dbgMethod("getSize()", mRendererGetSize);
    dbgMethod("createSwapchain", mRendererCreateSwapchain);

    dbgClass("GLRenderer", cGLRenderer);
    dbgMethod("getGLTextureId()", mGLRendererGetGLTextureId);

    // TransferType

    jclass cTransferType = getClass(env, "org.eclipse.fx.drift.TransferType");
    fTransferTypeId = env->GetFieldID(cTransferType, "id", "Ljava/lang/String;");
    mTransferTypeIsAvailable = env->GetMethodID(cTransferType, "isAvailable", "()Z");

    dbgClass("TransferType", cTransferType);
    dbgField("id", fTransferTypeId);
    dbgMethod("isAvailable()", mTransferTypeIsAvailable);

    // String
    jclass cString = getClass(env, "java.lang.String");
    mStringGetBytes = env->GetMethodID(cString, "getBytes", "()[B");

    dbgClass("String", cString);
    dbgMethod("getBytes()", mStringGetBytes);

    jclass cStandardTransferTypes = getClass(env, "org.eclipse.fx.drift.StandardTransferTypes"); //env->FindClass("org/eclipse/fx/drift/StandardTransferTypes");
    jfieldID fStandardTransferTypesMainMemory = env->GetStaticFieldID(cStandardTransferTypes, "MainMemory", "Lorg/eclipse/fx/drift/TransferType;");
    jfieldID fStandardTransferTypesIOSurface = env->GetStaticFieldID(cStandardTransferTypes, "IOSurface", "Lorg/eclipse/fx/drift/TransferType;");
    jfieldID fStandardTransferTypesNVDXInterop = env->GetStaticFieldID(cStandardTransferTypes, "NVDXInterop", "Lorg/eclipse/fx/drift/TransferType;");
    
    dbgClass("StandardTransferTypes", cStandardTransferTypes);
    dbgField("MainMemory", fStandardTransferTypesMainMemory);
    dbgField("IOSurface", fStandardTransferTypesIOSurface);
    dbgField("NVDXInterop", fStandardTransferTypesNVDXInterop);

    jobject mainMemory = env->GetStaticObjectField(cStandardTransferTypes, fStandardTransferTypesMainMemory);
    jobject ioSurface = env->GetStaticObjectField(cStandardTransferTypes, fStandardTransferTypesIOSurface);
    jobject nvdxInterop = env->GetStaticObjectField(cStandardTransferTypes, fStandardTransferTypesNVDXInterop);
    
    mainMemory = env->NewGlobalRef(mainMemory);
    ioSurface = env->NewGlobalRef(ioSurface);
    nvdxInterop = env->NewGlobalRef(nvdxInterop);

    std::cout << " * mainMemory = " << mainMemory << std::endl;
    std::cout << " * ioSurface = " << ioSurface << std::endl; 
    std::cout << " * nvdxInterop = " << nvdxInterop << std::endl;
    
    driftfx::StandardTransferTypes::MainMemory = getTransferType(env, mainMemory);
    driftfx::StandardTransferTypes::IOSurface = getTransferType(env, ioSurface);
    driftfx::StandardTransferTypes::NVDXInterop = getTransferType(env, nvdxInterop);


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
    std::cout << "txType: " << impl->getId() << std::endl;
    jobject transferType = impl->getJavaInstance();
    std::cout << "C: new SwapChainConfig(" << size << ", " << imageCount << ", " << presentationMode << ", " << transferType << ")" << std::endl;
    return env->NewObject(cSwapchainConfig, mSwapchainConfigConstructor, size, imageCount, presentationMode, transferType);
}

driftfx::SwapchainConfig internal::JNI::convertSwapchainConfig(JNIEnv* env, jobject swapchainConfig) {
    driftfx::SwapchainConfig config;
    
    std::cout << "GetObjectField(" << swapchainConfig << ", " << fSwapchainConfigSize << ") (size)" << std::endl;
    jobject size = env->GetObjectField(swapchainConfig, fSwapchainConfigSize);
    std::cout << " -> " << size << std::endl;
    config.size = convertVec2i(env, size);
    std::cout << "GetIntField(" << swapchainConfig << ", " << fSwapchainConfigImageCount << ") (imageCount)" << std::endl;
    config.imageCount = env->GetIntField(swapchainConfig, fSwapchainConfigImageCount);
    std::cout << " -> " << config.imageCount << std::endl;
    std::cout << "GetObjectField(" << swapchainConfig << ", " << fSwapchainConfigTransferType << ") (transferType)" << std::endl;
    jobject tt = env->GetObjectField(swapchainConfig, fSwapchainConfigTransferType);
    std::cout << " -> " << tt << std::endl;
    config.transferType = getTransferType(env, tt);
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
    std::cout << "CallObjectMethod("<< swapchain << ", " << mSwapchainGetConfig << ") (getConfig())" << std::endl << std::flush;
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

jstring internal::JNI::getTransferTypeId(JNIEnv* env, jobject transferType) {
    return (jstring) env->GetObjectField(transferType, fTransferTypeId);
}

jboolean internal::JNI::callTransferTypeIsAvailable(JNIEnv* env, jobject transferType) {
    return env->CallBooleanMethod(transferType, mTransferTypeIsAvailable);
}

jbyteArray internal::JNI::callStringGetBytes(JNIEnv* env, jstring str) {
    return (jbyteArray) env->CallObjectMethod(str, mStringGetBytes);
}

::std::string internal::JNI::convert(JNIEnv* env, jstring value) {
    std::cout << "calling getBytes with " << value << std::endl;
    const auto bytes = callStringGetBytes(env, value);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
    }
    std::cout << "got bytes " << bytes << std::endl;
    const auto length = env->GetArrayLength(bytes);
    const auto pBytes = env->GetByteArrayElements(bytes, nullptr);
    std::string result((char*)pBytes, length);
    env->ReleaseByteArrayElements(bytes, pBytes, JNI_ABORT);
    return result;
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
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
    }
    std::cout << "Got javaSwapchain = " << javaSwapchain << std::endl << std::flush;


    return new internal::SwapchainImpl(env, javaSwapchain);
}



internal::SwapchainImpl::SwapchainImpl(JNIEnv* _env, jobject _javaInstance) {
    std::cout << "SwapchainImpl(" << env << ", " << _javaInstance << ")" << std::endl << std::flush;
    this->env = _env;
    this->javaInstance = _javaInstance;

    jobject javaConfig = internal::JNI::callSwapchainGetConfig(env, javaInstance);
    this->config = internal::JNI::convertSwapchainConfig(env, javaConfig);
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
    return config;
}

internal::RenderTargetImpl::RenderTargetImpl(JNIEnv* _env, jobject _javaInstance) {
    this->env = _env;
    this->javaInstance = _javaInstance;
}

internal::TransferTypeImpl::TransferTypeImpl(JNIEnv* _env, jobject _javaInstance) {
    env = _env;
    javaInstance = _javaInstance;

    jstring jId = internal::JNI::getTransferTypeId(env, _javaInstance);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
    }
    std::cout << "got id: " << jId << std::endl << std::flush;

    const char* data = env->GetStringUTFChars(jId, 0);
    std::cout << "data: " << data << std::endl;

    id = internal::JNI::convert(env, jId);
}

::std::string internal::TransferTypeImpl::getId() {
    return id;
}

bool internal::TransferTypeImpl::isAvailable() {
    return (bool) internal::JNI::callTransferTypeIsAvailable(env, javaInstance);
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


driftfx::TransferType* internal::JNI::getTransferType(JNIEnv* env, jobject transferType) {

    jstring jId = getTransferTypeId(env, transferType);
    std::string id = convert(env, jId);

    std::cout << "looking up " << id << std::endl;

    auto it = transferTypes.find(id);
    if (it != transferTypes.end()) {
        std::cout << "! found in map " << it->second << std::endl;
        return it->second;
    } else {
        auto result = new TransferTypeImpl(env, transferType);
        transferTypes.insert({ id, result });
        std::cout << "! not found in map -> created it " << result << std::endl;

        return result;
    }
}

driftfx::TransferType* driftfx::getTransferType(JNIEnv* env, jobject javaTransferType) {
    return internal::JNI::getTransferType(env, javaTransferType);
}

void driftfx::initialize(JNIEnv* env, jobject classLoader) {

    std::cout << "CHANGE 0" << std::endl;

    internal::JNI::init(env, classLoader);
}

void driftfx::dispose(JNIEnv* env) {
    internal::JNI::dispose(env);
}