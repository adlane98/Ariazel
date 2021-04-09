#pragma once

#include "Event.h"

namespace Ariazel {
	class ARIAZEL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream sstream;
			sstream << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return sstream.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX;
		float m_MouseY;
	};

	class ARIAZEL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream sstream;
			sstream << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return sstream.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_XOffset;
		float m_YOffset;
	};



	class ARIAZEL_API MouseButtonEvent : public Event
	{
	public:

		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:

		MouseButtonEvent(int button) : m_Button(button) {}

		int m_Button;
	};


	class ARIAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream sstream;
			sstream << "MouseButtonPressedEvent: " << m_Button;
			return sstream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	private:
		int m_RepeatCount;
	};

	class ARIAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream sstream;
			sstream << "MouseButtonReleasedEvent: " << m_Button;
			return sstream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	};
}
