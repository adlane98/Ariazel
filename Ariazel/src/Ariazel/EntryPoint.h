#pragma once

#ifdef AZ_PLATFORM_WINDOWS


extern Ariazel::Application* Ariazel::CreateApplication();

int main(int argc, char **argv) 
{
	Ariazel::Log::Init();
	HZ_CORE_WARN("Init log");
	HZ_CORE_TRACE("Hola var={0}", 5);

	auto app = Ariazel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // AZ_PLATFORM_WINDOWS
