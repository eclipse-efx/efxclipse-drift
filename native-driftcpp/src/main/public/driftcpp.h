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

    struct Vec2d {
        double x;
        double y;
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
        /**
         * creates a new Swapchain.
         * <p>must be called from the rendering thread with a current OpenGL context</p>
         * @return a new swapchain
         */
        virtual Swapchain* createSwapchain(SwapchainConfig config) = 0;
        /**
         * returns the current size of the associated driftfx surface.
         * <p>this is the premultiplied size for the texture (logical size * screen scale * user scale)</p>
         * @return the size
         */
        virtual Vec2i getSize() = 0;
        /**
         * the current logical size of the associated driftfx surface.
         * @return the logical size
         */
        virtual Vec2d getLogicalSize() = 0;
        /**
         * the current screen scale of the associated driftfx surface as reported by javafx.
         * @return the screen scale.
         */
        virtual Vec2d getScreenScale() = 0;
         /**
         * the current user scale of the associated driftfx surface.
         * @return the user scale
         */
        virtual Vec2d getUserScale() = 0;
        virtual ~Renderer() = 0;
    };
    
    
    class GLRenderer {
    public:
        static GLuint getGLTextureId(RenderTarget* renderTarget);
    };
    
    
    // api entry point
    Renderer* initializeRenderer(JNIEnv* env, jobject javaRenderer);


    TransferType* getTransferType(JNIEnv* env, jobject javaTransferType);
    
    
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


#endif // _DRIFTCPP_H_
