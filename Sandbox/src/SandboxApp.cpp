#include "azpch.h"
#include <Ariazel.h>

class ExampleLayer : public Ariazel::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//AZ_INFO("Example Layer::Update");

		if (Ariazel::Input::IsKeyPressed(AZ_KEY_TAB))
			AZ_TRACE("Tab key is pressed");
	}

	void OnEvent(Ariazel::Event& event) override
	{
		if (event.GetEventType() == Ariazel::EventType::KeyPressed)
		{
			Ariazel::KeyPressedEvent& e = (Ariazel::KeyPressedEvent&) event;
			AZ_TRACE("{0}", e.GetKeyCode());
		}
	}
};

class Sandbox : public Ariazel::Application
{
public: 
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Ariazel::ImGuiLayer());
	}

	~Sandbox() 
	{

	}
};

Ariazel::Application* Ariazel::CreateApplication() 
{
	return new Sandbox();
}