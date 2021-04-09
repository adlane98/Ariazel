workspace "Ariazel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ariazel"
	location "Ariazel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AZ_PLATFORM_WINDOWS",
			"ARIAZEL_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AZ_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"Ariazel/src"

	}

	links
	{
		"Ariazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AZ_PLATFORM_WINDOWS"
		}	

	filter "configurations:Debug"
		defines "AZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AZ_DIST"
		optimize "On"