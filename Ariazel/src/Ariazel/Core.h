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

#ifdef AZ_DEBUG
	#define AZ_ENABLE_ASSERTS
#endif

#ifdef AZ_ENABLE_ASSERTS
	#define AZ_ASSERT(x, ...) { if(!(x)) { AZ_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AZ_CORE_ASSERT(x, ...) { if(!(x)) { AZ_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AZ_ASSERT(x, ...) 
	#define AZ_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)

#define AZ_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1) 

