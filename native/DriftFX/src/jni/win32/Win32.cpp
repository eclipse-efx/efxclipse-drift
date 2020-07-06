/*
 * Copyright (c) 2020 BestSolution.at and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     Christoph Caks <ccaks@bestsolution.at> - initial API and implementation
 */

#include <jni.h>
#include <windows.h>
#include <d3d9.h>
#include <iostream>
#include <iomanip>

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_Win32_nIUnknownAddRef(JNIEnv *env, jclass cls,
	jlong _pAddress) {
		IUnknown* pAddress = (IUnknown*) _pAddress;
		return pAddress->AddRef();
	}

	
extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_Win32_nIUnknownRelease(JNIEnv *env, jclass cls,
	jlong _pAddress) {
		IUnknown* pAddress = (IUnknown*) _pAddress;
		return pAddress->Release();
	}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_Win32_nIDirect3DDevice9CreateTexture(JNIEnv *env, jclass cls,
	jlong _d3d9DeviceEx, jint _width, jint _height, jint _levels, jint _usage, jint _format, jint _pool, jlong _texture, jlong _shareHandle) {
		IDirect3DDevice9Ex* d3d9DeviceEx = (IDirect3DDevice9Ex*) _d3d9DeviceEx;
		UINT width = (UINT) _width;
		UINT height = (UINT) _height;
		UINT levels = (UINT) _levels;
		DWORD usage = (DWORD) _usage;
		D3DFORMAT format = (D3DFORMAT) _format;
		D3DPOOL pool = (D3DPOOL) _pool;
		IDirect3DTexture9** texture = (IDirect3DTexture9**) _texture;
		HANDLE* shareHandle = (HANDLE*) _shareHandle;



		// TODO hresult handling
		HRESULT res = d3d9DeviceEx->CreateTexture(width, height, levels, usage, format, pool, texture, shareHandle);
		if (FAILED(res)) {
			switch (res) {
			case D3DERR_INVALIDCALL: std::cerr << "D3DERR_INVALIDCALL" << std::endl; break;
			case D3DERR_OUTOFVIDEOMEMORY:  std::cerr <<  "D3DERR_OUTOFVIDEOMEMORY"  << std::endl; break;
			case E_OUTOFMEMORY:  std::cerr << "E_OUTOFMEMORY"  << std::endl; break;
			default:  std::cerr << "Unknown DirectX Error hResult=" << std::hex << res << std::endl;
			}
		}


		// IDirect3DTexture9* tex2;

		// HRESULT res2 = d3d9DeviceEx->CreateTexture(width, height, levels, usage, format, pool, &tex2, &test);
		// std::cout << "2: " << res2 << std::endl;

		// if (FAILED(res2)) {
		// 	switch (res2) {
		// 	case D3DERR_INVALIDCALL: std::cerr << "D3DERR_INVALIDCALL" << std::endl; break;
		// 	case D3DERR_OUTOFVIDEOMEMORY:  std::cerr <<  "D3DERR_OUTOFVIDEOMEMORY"  << std::endl; break;
		// 	case E_OUTOFMEMORY:  std::cerr << "E_OUTOFMEMORY"  << std::endl; break;
		// 	default:  std::cerr << "Unknown DirectX Error hResult=" << std::hex << res2 << std::endl;
		// 	}
		// }

		return res;
	}
	