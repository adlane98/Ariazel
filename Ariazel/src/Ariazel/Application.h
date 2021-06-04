#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Ariazel/LayerStack.h"

#include "Ariazel/ImGui/ImGuiLayer.h"

#include "Ariazel/Renderer/Shader.h"
#include "Ariazel/Renderer/Buffer.h"
#include "Ariazel/Renderer/VertexArray.h"

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

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}
