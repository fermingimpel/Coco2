#include "Window.h"

#include "glew.h"
#include "glfw3.h"

#include <iostream>

namespace Coco2Engine {
	Window::Window() {
	}
	bool Window::CreateWindow(int width, int height, const char* windowName, GLFWmonitor* fullScreen) {
		MainWindow = glfwCreateWindow(width, height, windowName, fullScreen, NULL);

		if (!MainWindow) {
			std::cout << "Fail to create GLFW window" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(MainWindow);

		return true;

	}

	void Window::DestroyWindow() {
		glfwDestroyWindow(MainWindow);
	}

	bool Window::CheckIfWindowIsOpen() {
		return (!glfwWindowShouldClose(MainWindow));
	}

	void Window::ClearWindow(float r, float g, float b) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(r, g, b, 1.0f);
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers(MainWindow);
	}

}