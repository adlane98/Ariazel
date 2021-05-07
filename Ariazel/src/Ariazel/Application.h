#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Ariazel/LayerStack.h"

#include "Ariazel/ImGui/ImGuiLayer.h"

#include "Ariazel/Renderer/Shader.h"

namespace Ariazel {

	class ARIAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}

