#include <Ariazel.h>

class Sandbox : public Ariazel::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

Ariazel::Application* Ariazel::CreateApplication() 
{
	return new Sandbox();
}