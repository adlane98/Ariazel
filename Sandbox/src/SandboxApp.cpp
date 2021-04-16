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
		AZ_INFO("Example Layer::Update");
	}

	void OnEvent(Ariazel::Event& event) override
	{
		AZ_TRACE("{0}", event);
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