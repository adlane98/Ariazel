workspace "Ariazel"
	architecture "x64"
	startproject "Sandbox"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Ariazel/vendor/GLFW/include"
IncludeDir["Glad"] = "Ariazel/vendor/Glad/include"
IncludeDir["imGui"] = "Ariazel/vendor/imGui"
IncludeDir["glm"] = "Ariazel/vendor/glm"

include "Ariazel/vendor/GLFW"
include "Ariazel/vendor/Glad"
include "Ariazel/vendor/imGui"


project "Ariazel"
	location "Ariazel"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "azpch.h"
	pchsource "Ariazel/src/azpch.cpp"

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"imGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

	defines
	{
		"AZ_PLATFORM_WINDOWS",
		"ARIAZEL_BUILD_DLL",
		"GLFW_INCLUDE_NONE"
	}

	filter "configurations:Debug"
		defines "AZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AZ_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"Ariazel/vendor/spdlog/include",
		"Ariazel/src",
		"%{IncludeDir.glm}",
		"Ariazel/vendor"
	}

	links
	{
		"Ariazel"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"AZ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AZ_DIST"
		runtime "Release"
		optimize "on"
