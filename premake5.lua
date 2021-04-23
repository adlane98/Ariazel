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
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"AZ_PLATFORM_WINDOWS",
			"ARIAZEL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "AZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AZ_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.glm}"
	}

	links
	{
		"Ariazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"AZ_PLATFORM_WINDOWS"
		}	

	filter "configurations:Debug"
		defines "AZ_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AZ_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AZ_DIST"
		runtime "Release"
		optimize "On"
