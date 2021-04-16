#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Ariazel {

	class ARIAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

