#include "azpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>


namespace Ariazel {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1) 

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}


	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		AZ_CORE_TRACE("{0}", e);
	}

	void Application::Run() 
	{
		while (m_Running)
		{
			glClearColor(1, 0.26, 0.45, 0.12);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}