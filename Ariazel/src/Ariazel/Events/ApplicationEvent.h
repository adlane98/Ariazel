#pragma once

#include "Event.h"


namespace Ariazel {
	class ARIAZEL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int length) : m_Width(width), m_Length(length) {}

		inline float GetWidth() const { return m_Width; }
		inline float GetLength() const { return m_Length; }

		std::string ToString() const override
		{
			std::stringstream sstream;
			sstream << "WindowResizeEvent: " << m_Width << ", " << m_Length;
			return sstream.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width;
		unsigned int m_Length;
	};

	class ARIAZEL_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

	
		/*std::string ToString() const override
		{
			std::stringstream sstream;
			sstream << "WindowCloseEvent";
			return sstream.str();
		}*/

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	class ARIAZEL_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ARIAZEL_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ARIAZEL_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
