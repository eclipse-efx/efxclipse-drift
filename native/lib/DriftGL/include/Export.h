
#ifndef _DRIFTGL_EXPORT_H_
#define _DRIFTGL_EXPORT_H_

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

#endif