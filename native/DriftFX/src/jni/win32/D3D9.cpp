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

HWND createWindow() {
    
    HINSTANCE hInst = GetModuleHandle(NULL);

	// create window

	const char* className = "Direct3D";
	const char* windowName = "Direct3DWindow";
	int winX = 0; int winY = 0; int winHeight = 300; int winWidth = 400;
	WNDCLASS wndClass;
	wndClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = DefWindowProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInst;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = className;
	RegisterClass(&wndClass);

	HWND hWnd = CreateWindow(
			className, windowName,
			WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
			winX, winY, winWidth, winHeight,
			NULL, NULL, hInst, NULL);

	UpdateWindow(hWnd);

    return hWnd;
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_D3D9_doCreateOffscreenDevice(JNIEnv *env, jclass cls) {
	IDirect3D9Ex* d3d9;
    IDirect3DDevice9Ex* d3d9Device;
    Direct3DCreate9Ex(D3D_SDK_VERSION, &d3d9);

    HWND hWnd = createWindow();

    D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;

	HRESULT hresult = d3d9->CreateDeviceEx(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			NULL,
			&d3d9Device);
    //std::cerr << "hresult = " << hresult << std::endl;
    return (jlong) d3d9Device;
}

extern "C" JNIEXPORT jlong JNICALL Java_org_eclipse_fx_drift_internal_jni_win32_CreateDeviceEx(JNIEnv *env, jclass cls, jlong _d3d9Ex, 
    jint _Adapter, 
    jint _DeviceType, 
    jlong _hFocusWindow, 
    jint _BehaviorFlags, 
    jlong _pPresentationParameters, 
    jlong _pFullscreenDisplayMode, 
    jlong _ppReturnedDeviceInterface) {

    IDirect3D9Ex* d3d9Ex = (IDirect3D9Ex*) _d3d9Ex;
    UINT Adapter = (UINT) _Adapter;
    D3DDEVTYPE DeviceType = (D3DDEVTYPE) _DeviceType;
    HWND hFocusWindow = (HWND) _hFocusWindow;
    DWORD BehaviorFlags = (DWORD) _BehaviorFlags;
    D3DPRESENT_PARAMETERS* pPresentationParameters = (D3DPRESENT_PARAMETERS*) _pPresentationParameters;
    D3DDISPLAYMODEEX* pFullscreenDisplayMode = (D3DDISPLAYMODEEX*) _pFullscreenDisplayMode;
    
    IDirect3DDevice9Ex* ppReturnedDeviceInterface = (IDirect3DDevice9Ex*) _ppReturnedDeviceInterface;

    return d3d9Ex->CreateDeviceEx(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, pFullscreenDisplayMode, &ppReturnedDeviceInterface);
}
