#pragma once

#include "Ariazel/Layer.h"
#include "Ariazel/Events/KeyEvent.h"
#include "Ariazel/Events/MouseEvent.h"
#include "Ariazel/Events/ApplicationEvent.h"

namespace Ariazel {
	class ARIAZEL_API ImGuiLayer: public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	
	private:
		float m_Time = 0;
	};
}