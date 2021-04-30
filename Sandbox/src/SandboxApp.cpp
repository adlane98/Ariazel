#include "azpch.h"
#include <Ariazel.h>

#include "imGui/imgui.h"

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

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello world");
		ImGui::End();
	}
};

class Sandbox : public Ariazel::Application
{
public: 
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() 
	{

	}
};

Ariazel::Application* Ariazel::CreateApplication() 
{
	return new Sandbox();
}