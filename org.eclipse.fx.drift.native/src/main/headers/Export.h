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

#ifndef _DRIFTGL_EXPORT_H_
#define _DRIFTGL_EXPORT_H_

#define DRIFTGL_EXPORT

/*

#if defined _WIN32

	#ifdef BUILDING_DLL
		#ifdef __GNUC__
			#define DRIFTGL_EXPORT __attribute__ ((dllexport))
		#else
			#define DRIFTGL_EXPORT __declspec(dllexport)
		#endif
	#else
		#ifdef __GNUC__
			#define DRIFTGL_EXPORT __attribute__ ((dllimport))
		#else
			#define DRIFTGL_EXPORT __declspec(dllimport)
		#endif
	#endif
	#define DLL_LOCAL
#else
	#if __GNUC__ >= 4
		#define DRIFTGL_EXPORT __attribute__ ((visibility ("default")))
		#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
	#else
		#define DRIFTGL_EXPORT
		#define DLL_LOCAL
	#endif
#endif

*/
#endif