#include "azpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>

#include <glad/glad.h>


namespace Ariazel {
	OpenGLContext::OpenGLContext(GLFWwindow * windowHandle) : m_WindowHandle(windowHandle)
	{
		AZ_CORE_ASSERT(windowHandle, "Handle is null");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AZ_CORE_ASSERT(status, "Failed to initialize Glad");
		
		AZ_CORE_INFO("OpenGL Info:");
		AZ_CORE_INFO("Vendor: {0} ", glGetString(GL_VENDOR));
		AZ_CORE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
		AZ_CORE_INFO("Version: {0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}