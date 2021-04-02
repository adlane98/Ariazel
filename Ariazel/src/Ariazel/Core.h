#pragma once

#ifdef AZ_PLATFORM_WINDOWS
	#ifdef ARIAZEL_BUILD_DLL
		#define ARIAZEL_API __declspec(dllexport)
	#else
		#define ARIAZEL_API __declspec(dllimport)
	#endif
/*
#else
	#error Hazel only support windows
*/
#endif
