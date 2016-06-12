#include "window.h"

#include <iostream>

namespace vortex { namespace graphics {

	void windowResize(GLFWwindow *window, int width, int height);

	Window::Window(const char *name, int width, int height)
	{
		m_Name = name;
		m_Width = width;
		m_Height = height;

		if (!init())
		{
			glfwTerminate();
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::initShaders()
	{
		_colorProgram.compileShaders("src/graphics/shaders/ColorShader.vert", "src/graphics/shaders/ColorShader.frag");
		_colorProgram.addAttribute("vertexPosition");
		_colorProgram.addAttribute("vertexColor");
		_colorProgram.linkShaders();
	}

	void Window::sendDataToOpenGL()
	{
		ShapeData tri = Sprite::drawTriangle();

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (char*)(sizeof(float) * 4));
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to create window! Send much kelp!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW!" << std::endl;
		}

		sendDataToOpenGL();
		initShaders();

		return true;
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void windowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

} }
