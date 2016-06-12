#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ShaderManager.h"
#include "ShapeData.h"
#include "Sprite.h"

namespace vortex { namespace graphics {
	class Window
	{
	public:
		GLFWwindow *m_Window;
	private:
		int m_Width, m_Height;
		const char *m_Name;
		bool m_Closed;
		ShaderManager _colorProgram;

	public:
		Window(const char *name, int width, int height);
		~Window();
		bool closed() const;
		void update();
		void clear() const;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline ShaderManager getProgram() const { return _colorProgram; }

	private:
		bool init();
		void initShaders();
		void sendDataToOpenGL();
	};
} }

