#pragma once

#include "Ariazel/Core.h"
#include "Ariazel/Layer.h"

namespace Ariazel {
	class ARIAZEL_API ImGuiLayer: public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0;
	};
}