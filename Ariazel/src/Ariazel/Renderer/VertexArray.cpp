#include "azpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Ariazel {
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: AZ_CORE_ASSERT(false, "RendererAPI::None is not supported"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
		default: AZ_CORE_ASSERT(false, "This RendererAPI type is not supported"); return nullptr;
		}
	}
}
