/* ******************************************************************************
 * Copyright (c) 2019, 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials 
 * are made available under the terms of the Eclipse Public License 2.0 
 * which is available at http://www.eclipse.org/legal/epl-2.0
 *
 * SPDX-License-Identifier: EPL-2.0
 * 
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 * ******************************************************************************/
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
        static jclass getClass(JNIEnv* env, const char* name);
        static jmethodID getMethodID(JNIEnv* env, const char* clazzName, jclass clazz, const char* name, const char* signature);
        static jmethodID getStaticMethodID(JNIEnv* env, const char* clazzName, jclass clazz, const char* name, const char* signature);
        static jfieldID getFieldID(JNIEnv* env, const char* clazzName, jclass clazz, const char* name, const char* signature);
        static jfieldID getStaticFieldID(JNIEnv* env, const char* clazzName, jclass clazz, const char* name, const char* signature);
        
    private:
        static jobject classLoader;
        
        // Class
    private:
        static jclass cClass;
        static jmethodID mClassForName;
    public:
        
        
        // Vec2i
    private:
        static jclass cVec2i;
        static jmethodID mVec2iConstructor;
        static jfieldID fVec2iX;
        static jfieldID fVec2iY;
    public:
        static driftfx::Vec2i convertVec2i(JNIEnv* env, jobject vec2i);
        static jobject convertVec2i(JNIEnv* env, driftfx::Vec2i vec2i);
        
        // Vec2d
    private:
        static jclass cVec2d;
        static jmethodID mVec2dConstructor;
        static jfieldID fVec2dX;
        static jfieldID fVec2dY;
    public:
        static driftfx::Vec2d convertVec2d(JNIEnv* env, jobject vec2d);
        static jobject convertVec2d(JNIEnv* env, driftfx::Vec2d vec2d);

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
        static jmethodID mRendererGetLogicalSize;
        static jmethodID mRendererGetScreenScale;
        static jmethodID mRendererGetUserScale;
        static jmethodID mRendererCreateSwapchain;
    public:
        static jobject callRendererGetSize(JNIEnv* env, jobject renderer);
        static jobject callRendererGetLogicalSize(JNIEnv* env, jobject renderer);
        static jobject callRendererGetScreenScale(JNIEnv* env, jobject renderer);
        static jobject callRendererGetUserScale(JNIEnv* env, jobject renderer);
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
        driftfx::Vec2d getLogicalSize();
        driftfx::Vec2d getScreenScale();
        driftfx::Vec2d getUserScale();
        
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

// Vec2d
jclass internal::JNI::cVec2d;
jmethodID internal::JNI::mVec2dConstructor;
jfieldID internal::JNI::fVec2dX;
jfieldID internal::JNI::fVec2dY;

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
jmethodID internal::JNI::mRendererGetLogicalSize;
jmethodID internal::JNI::mRendererGetScreenScale;
jmethodID internal::JNI::mRendererGetUserScale;
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
jmethodID internal::JNI::getMethodID(JNIEnv* env, const char* clazzName, jclass clazz, const char* name, const char* signature) {
    auto result = env->GetMethodID(clazz, name, signature);
    if (result == nullptr) std::cerr << "lookup " << clazzName << "#" << name << " failed! " << std::endl;
    return result;
}
jmethodID internal::JNI::getStaticMethodID(JNIEnv* env, const char* clazzName, jclass clazz, const char* name, const char* signature) {
    auto result = env->GetStaticMethodID(clazz, name, signature);
    if (result == nullptr) std::cerr << "lookup " << clazzName << "#" << name << " failed! " << std::endl;
    return result;
}
jfieldID internal::JNI::getFieldID(JNIEnv* env, const char* clazzName, jclass clazz, const char* name, const char* signature) {
    auto result = env->GetFieldID(clazz, name, signature);
    if (result == nullptr) std::cerr << "lookup " << clazzName << "#" << name << " failed! " << std::endl;
    return result;
}
jfieldID internal::JNI::getStaticFieldID(JNIEnv* env, const char* clazzName, jclass clazz, const char* name, const char* signature) {
    auto result = env->GetStaticFieldID(clazz, name, signature);
    if (result == nullptr) std::cerr << "lookup " << clazzName << "#" << name << " failed! " << std::endl;
    return result;
}

void internal::JNI::init(JNIEnv* env, jobject _classLoader) {
    classLoader = env->NewGlobalRef(_classLoader);
    // Class
    cClass = env->FindClass("java/lang/Class");
    cClass = (jclass)env->NewGlobalRef(cClass);
    mClassForName = getStaticMethodID(env, "java.lang.Class", cClass, "forName", "(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;");

    // Vec2i
    const char* Vec2i = "org.eclipse.fx.drift.Vec2i";
    cVec2i = getClass(env, Vec2i);
    cVec2i = (jclass)env->NewGlobalRef(cVec2i);
    mVec2iConstructor = getMethodID(env, Vec2i, cVec2i, "<init>", "(II)V");
    fVec2iX = getFieldID(env, Vec2i, cVec2i, "x", "I");
    fVec2iY = getFieldID(env, Vec2i, cVec2i, "y", "I");

    // Vec2i
    const char* Vec2d = "org.eclipse.fx.drift.Vec2d";
    cVec2d = getClass(env, Vec2d);
    cVec2d = (jclass)env->NewGlobalRef(cVec2d);
    mVec2dConstructor = getMethodID(env, Vec2d, cVec2d, "<init>", "(DD)V");
    fVec2dX = getFieldID(env, Vec2i, cVec2d, "x", "D");
    fVec2dY = getFieldID(env, Vec2i, cVec2d, "y", "D");

    // SwapchainConfig
    const char* SwapchainConfig = "org.eclipse.fx.drift.SwapchainConfig";
    cSwapchainConfig = getClass(env, SwapchainConfig);
    cSwapchainConfig = (jclass)env->NewGlobalRef(cSwapchainConfig);
    mSwapchainConfigConstructor = getMethodID(env, SwapchainConfig, cSwapchainConfig, "<init>", "(Lorg/eclipse/fx/drift/Vec2i;ILorg/eclipse/fx/drift/PresentationMode;Lorg/eclipse/fx/drift/TransferType;)V");
    fSwapchainConfigSize = getFieldID(env, SwapchainConfig, cSwapchainConfig, "size", "Lorg/eclipse/fx/drift/Vec2i;");
    fSwapchainConfigImageCount = getFieldID(env, SwapchainConfig, cSwapchainConfig, "imageCount", "I");
    fSwapchainConfigPresentationMode = getFieldID(env, SwapchainConfig, cSwapchainConfig, "presentationMode", "Lorg/eclipse/fx/drift/PresentationMode;");
    fSwapchainConfigTransferType = getFieldID(env, SwapchainConfig, cSwapchainConfig, "transferType", "Lorg/eclipse/fx/drift/TransferType;");

    // Swapchain
    const char* Swapchain = "org.eclipse.fx.drift.Swapchain";
    jclass cSwapchain = getClass(env, Swapchain);
    mSwapchainAcquire = getMethodID(env, Swapchain, cSwapchain, "acquire", "()Lorg/eclipse/fx/drift/RenderTarget;");

    // mSwapchainTryAcquire // TODO generics!?
    mSwapchainPresent = getMethodID(env, Swapchain, cSwapchain, "present", "(Lorg/eclipse/fx/drift/RenderTarget;)V");
    mSwapchainDispose = getMethodID(env, Swapchain, cSwapchain, "dispose", "()V");
    mSwapchainGetConfig = getMethodID(env, Swapchain, cSwapchain, "getConfig", "()Lorg/eclipse/fx/drift/SwapchainConfig;");

    // Renderer
    const char* Renderer = "org.eclipse.fx.drift.Renderer";
    jclass cRenderer = getClass(env, Renderer); //env->FindClass("org/eclipse/fx/drift/Renderer");
    mRendererGetSize = getMethodID(env, Renderer, cRenderer, "getSize", "()Lorg/eclipse/fx/drift/Vec2i;");
    mRendererGetLogicalSize = getMethodID(env, Renderer, cRenderer, "getLogicalSize", "()Lorg/eclipse/fx/drift/Vec2d;");
    mRendererGetScreenScale = getMethodID(env, Renderer, cRenderer, "getScreenScale", "()Lorg/eclipse/fx/drift/Vec2d;");
    mRendererGetUserScale = getMethodID(env, Renderer, cRenderer, "getUserScale", "()Lorg/eclipse/fx/drift/Vec2d;");
    mRendererCreateSwapchain = getMethodID(env, Renderer, cRenderer, "createSwapchain", "(Lorg/eclipse/fx/drift/SwapchainConfig;)Lorg/eclipse/fx/drift/Swapchain;");
    
    // GLRenderer
    const char* GLRenderer = "org.eclipse.fx.drift.GLRenderer";
    cGLRenderer = getClass(env, GLRenderer);
    cGLRenderer = (jclass)env->NewGlobalRef(cGLRenderer);
    mGLRendererGetGLTextureId = getStaticMethodID(env, GLRenderer, cGLRenderer, "getGLTextureId", "(Lorg/eclipse/fx/drift/RenderTarget;)I");

    // TransferType
    const char* TransferType = "org.eclipse.fx.drift.TransferType";
    jclass cTransferType = getClass(env, TransferType);
    fTransferTypeId = getFieldID(env, TransferType, cTransferType, "id", "Ljava/lang/String;");
    mTransferTypeIsAvailable = getMethodID(env, TransferType, cTransferType, "isAvailable", "()Z");

    // String
    const char* String = "java.lang.String";
    jclass cString = getClass(env, String);
    mStringGetBytes = getMethodID(env, String, cString, "getBytes", "()[B");

    const char* StandardTransferTypes = "org.eclipse.fx.drift.StandardTransferTypes";
    jclass cStandardTransferTypes = getClass(env, StandardTransferTypes); //env->FindClass("org/eclipse/fx/drift/StandardTransferTypes");
    jfieldID fStandardTransferTypesMainMemory = getStaticFieldID(env, StandardTransferTypes, cStandardTransferTypes, "MainMemory", "Lorg/eclipse/fx/drift/TransferType;");
    jfieldID fStandardTransferTypesIOSurface = getStaticFieldID(env, StandardTransferTypes, cStandardTransferTypes, "IOSurface", "Lorg/eclipse/fx/drift/TransferType;");
    jfieldID fStandardTransferTypesNVDXInterop = getStaticFieldID(env, StandardTransferTypes, cStandardTransferTypes, "NVDXInterop", "Lorg/eclipse/fx/drift/TransferType;");

    jobject mainMemory = env->GetStaticObjectField(cStandardTransferTypes, fStandardTransferTypesMainMemory);
    jobject ioSurface = env->GetStaticObjectField(cStandardTransferTypes, fStandardTransferTypesIOSurface);
    jobject nvdxInterop = env->GetStaticObjectField(cStandardTransferTypes, fStandardTransferTypesNVDXInterop);
    
    mainMemory = env->NewGlobalRef(mainMemory);
    ioSurface = env->NewGlobalRef(ioSurface);
    nvdxInterop = env->NewGlobalRef(nvdxInterop);
    
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

driftfx::Vec2d internal::JNI::convertVec2d(JNIEnv* env, jobject vec2d) {
    jdouble x = env->GetDoubleField(vec2d, fVec2dX);
    jdouble y = env->GetDoubleField(vec2d, fVec2dY);
    driftfx::Vec2d result;
    result.x = x;
    result.y = y;
    return result;
}

jobject internal::JNI::convertVec2d(JNIEnv* env, driftfx::Vec2d vec2d) {
    jdouble x = vec2d.x;
    jdouble y = vec2d.y;
    return env->NewObject(cVec2d, mVec2dConstructor, x, y);
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
    return env->CallObjectMethod(swapchain, mSwapchainGetConfig);
}



jobject internal::JNI::callRendererGetSize(JNIEnv* env, jobject renderer) {
    return env->CallObjectMethod(renderer, mRendererGetSize);
}

jobject internal::JNI::callRendererGetLogicalSize(JNIEnv* env, jobject renderer) {
    return env->CallObjectMethod(renderer, mRendererGetLogicalSize);
}

jobject internal::JNI::callRendererGetScreenScale(JNIEnv* env, jobject renderer) {
    return env->CallObjectMethod(renderer, mRendererGetScreenScale);
}

jobject internal::JNI::callRendererGetUserScale(JNIEnv* env, jobject renderer) {
    return env->CallObjectMethod(renderer, mRendererGetUserScale);
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
    const auto bytes = callStringGetBytes(env, value);
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

driftfx::Vec2d internal::RendererImpl::getLogicalSize() {
    jobject javaSize = internal::JNI::callRendererGetLogicalSize(env, javaInstance);
    return internal::JNI::convertVec2d(env, javaSize);
}

driftfx::Vec2d internal::RendererImpl::getScreenScale() {
    jobject javaSize = internal::JNI::callRendererGetScreenScale(env, javaInstance);
    return internal::JNI::convertVec2d(env, javaSize);
}

driftfx::Vec2d internal::RendererImpl::getUserScale() {
    jobject javaSize = internal::JNI::callRendererGetUserScale(env, javaInstance);
    return internal::JNI::convertVec2d(env, javaSize);
}

driftfx::Swapchain* internal::RendererImpl::createSwapchain(driftfx::SwapchainConfig config) {
    jobject javaSwapchain = internal::JNI::callRendererCreateSwapchain(env, javaInstance, internal::JNI::convertSwapchainConfig(env, config));
    return new internal::SwapchainImpl(env, javaSwapchain);
}



internal::SwapchainImpl::SwapchainImpl(JNIEnv* _env, jobject _javaInstance) {
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
    const char* data = env->GetStringUTFChars(jId, 0);
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

    auto it = transferTypes.find(id);
    if (it != transferTypes.end()) {
        return it->second;
    } else {
        auto result = new TransferTypeImpl(env, transferType);
        transferTypes.insert({ id, result });
        return result;
    }
}

driftfx::TransferType* driftfx::getTransferType(JNIEnv* env, jobject javaTransferType) {
    return internal::JNI::getTransferType(env, javaTransferType);
}

void driftfx::initialize(JNIEnv* env, jobject classLoader) {
    internal::JNI::init(env, classLoader);
}

void driftfx::dispose(JNIEnv* env) {
    internal::JNI::dispose(env);
}
