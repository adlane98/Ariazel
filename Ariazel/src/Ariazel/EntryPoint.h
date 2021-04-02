#pragma once

#ifdef AZ_PLATFORM_WINDOWS


extern Ariazel::Application* Ariazel::CreateApplication();

int main(int argc, char **argv) 
{
	auto app = new Ariazel::Application();
	app->Run();
	delete app;
	return 0;
}

#endif // AZ_PLATFORM_WINDOWS
