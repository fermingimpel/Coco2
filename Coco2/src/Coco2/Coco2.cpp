#include "Coco2.h"

#include "glew.h"
#include "glfw3.h"

#include <iostream>

#include "Window/Window.h"

namespace Coco2Engine {
	Coco2::Coco2() {
		_window = nullptr;
	}

	bool Coco2::Coco2_StartEngine(int width, int height, const char* windowName) {

		if (!glfwInit()) {
		
			std::cout << "GLFW Initialization failed" << std::endl;
			glfwTerminate();
		
			return false;
		}
		
		std::cout << "GLFW Initialized" << std::endl;
		
		if (!glewInit() != GLEW_OK) {
			std::cout << "GLEW Initialization failed" << std::endl;
			glfwTerminate();
			return false;
		
		}
		
		std::cout << "GLEW Initialized" << std::endl;
		
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		
		std::cout << "Windows Hint setted" << std::endl;
		
		_window = new Window();
		
		if (!_window) {
			std::cout << "Failed to create Class Window" << std::endl;
			return false;
		}
		
		_window->CreateWindow(width, height, windowName, NULL);
		
		int bufferWidth;
		int bufferHeight;
		
		glfwGetFramebufferSize(_window->MainWindow, &bufferWidth, &bufferHeight);

		glEnable(GL_DEPTH);

		return true;
	}

	void Coco2::Coco2_UpdateEngine() {
		while (_window->CheckIfWindowIsOpen()) {
			Update();
			glfwPollEvents();
		}
	}

	void Coco2::Coco2_EndEngine() {
		if (_window) {
			delete _window;
			_window = nullptr;
		}

	}

	void Coco2::Coco2_ClearWindow(float redColour, float greenColour, float blueColour) {
		_window->ClearWindow(redColour, greenColour, blueColour);
	}

	void Coco2::Coco2_SwapBuffers() {
		_window->SwapBuffers();
	}

}