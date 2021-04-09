#include "azpch.h"
#include "Application.h"

#include "Ariazel/Events/MouseEvent.h"
#include "Ariazel/Log.h"


namespace Ariazel {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run() 
	{
		MouseButtonPressedEvent e(2);

		if (e.IsInCategory(EventCategoryApplication))
			AZ_TRACE(e);

		while (true);
	}
}