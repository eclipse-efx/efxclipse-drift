
#ifndef _DRIFTCPP_EXPORT_H_
#define _DRIFTCPP_EXPORT_H_

#if defined _WIN32

	#ifdef BUILDING_DLL
		#ifdef __GNUC__
			#define DRIFTCPP_EXPORT __attribute__ ((dllexport))
		#else
			#define DRIFTCPP_EXPORT __declspec(dllexport)
		#endif
	#else
		#ifdef __GNUC__
			#define DRIFTCPP_EXPORT __attribute__ ((dllimport))
		#else
			#define DRIFTCPP_EXPORT __declspec(dllimport)
		#endif
	#endif
	#define DLL_LOCAL
#else
	#if __GNUC__ >= 4
		#define DRIFTCPP_EXPORT __attribute__ ((visibility ("default")))
		#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
	#else
		#define DRIFTCPP_EXPORT
		#define DLL_LOCAL
	#endif
#endif

#endif