#include "Coco2.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>
#include <iostream>

namespace Coco2Engine {
	Coco2::Coco2() {
	
	}

	bool Coco2::Coco2_StartEngine(int width, int height, const char* windowName) {

		if (!glfwInit()) {
		
			std::cout << "GLFW Initialization failed" << std::endl;
			glfwTerminate();
		
			return false;
		}
		
		std::cout << "GLFW Initialized" << std::endl;
		
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		
		std::cout << "Windows Hint setted" << std::endl;
		
		Coco2_SetMainWindow(new Window());
		
		if (!Coco2_GetMainWindow()) {
			std::cout << "Failed to create Class Window" << std::endl;
			return false;
		}
		
		Coco2_GetMainWindow()->CreateWindow(width, height, windowName, NULL);
		
		int bufferWidth;
		int bufferHeight;
		
		glfwGetFramebufferSize(Coco2_GetMainWindow()->MainWindow, &bufferWidth, &bufferHeight);

		Coco2_GetMainWindow()->InitWindow();

		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK) {
			std::cout << "GLEW Initialization failed" << std::endl;
			glfwTerminate();
			return false;

		}

		std::cout << "GLEW Initialized" << std::endl;

		glEnable(GL_DEPTH);

		Coco2_SetMainShader(new Shader());
		if (!Coco2_GetMainShader()) {
			std::cout << "Failed to create Class Shader" << std::endl;
			return false;
		}
		
		Coco2_GetMainShader()->CreateFromLocation("res/Shaders/vertex.shader", "res/Shaders/fragment.shader");
	
		Coco2_SetMainCamera(new Camera());
		if (!Coco2_GetMainCamera()) {
			std::cout << "Failed to create Class Camera" << std::endl;
			return false;
		}

		return true;
	}

	void Coco2::Coco2_UpdateEngine() {
		while (Coco2_GetMainWindow()->CheckIfWindowIsOpen()) {
			float DeltaTime;
			Timer::DeltaTime(DeltaTime);
			Update(DeltaTime);
			glfwPollEvents();
		}
	}

	void Coco2::Coco2_EndEngine() {
		if (Coco2_GetMainWindow()) {
			delete Coco2_GetMainWindow();
		}
		if (Coco2_GetMainShader()) {
			Coco2_GetMainShader()->ClearShader();
			delete Coco2_GetMainShader();
		}
		if (Coco2_GetMainCamera()) {
			delete Coco2_GetMainCamera();
		}
	}

	void Coco2::Coco2_ClearWindow(float redColour, float greenColour, float blueColour) {
		Coco2_GetMainWindow()->ClearWindow(redColour, greenColour, blueColour);
	}

	void Coco2::Coco2_SwapBuffers() {
		Coco2_GetMainWindow()->SwapBuffers();
	}

}