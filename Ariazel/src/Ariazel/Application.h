#pragma once

#include "Core.h"

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

