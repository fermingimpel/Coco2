#include "Coco2.h"

#include <glew/glew.h>
#include <glfw/glfw3.h>
#include <iostream>

#include "Extras/GameplayStatics.h"

#include "Window/Window.h"
#include "Shader/Shader.h"
#include "Camera/Camera.h"

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
		
		SetMainWindow(new Window());
		
		if (!GetMainWindow()) {
			std::cout << "Failed to create Class Window" << std::endl;
			return false;
		}
		
		GetMainWindow()->CreateWindow(width, height, windowName, NULL);
		
		int bufferWidth;
		int bufferHeight;
		
		glfwGetFramebufferSize(GetMainWindow()->MainWindow, &bufferWidth, &bufferHeight);

		GetMainWindow()->InitWindow();

		glewExperimental = GL_TRUE;

		if (glewInit() != GLEW_OK) {
			std::cout << "GLEW Initialization failed" << std::endl;
			glfwTerminate();
			return false;

		}

		std::cout << "GLEW Initialized" << std::endl;

		glEnable(GL_DEPTH);

		SetMainShader(new Shader());
		if (!GetMainShader()) {
			std::cout << "Failed to create Class Shader" << std::endl;
			return false;
		}
		
		GetMainShader()->CreateFromLocation("res/Shaders/vertex.shader", "res/Shaders/fragment.shader");
	
		SetMainCamera(new Camera());
		if (!GetMainCamera()) {
			std::cout << "Failed to create Class Camera" << std::endl;
			return false;
		}

		return true;
	}

	void Coco2::Coco2_UpdateEngine() {
		while (GetMainWindow()->CheckIfWindowIsOpen()) {
			float DeltaTime;
			Timer::DeltaTime(DeltaTime);
			Update(DeltaTime);
			glfwPollEvents();
		}
	}

	void Coco2::Coco2_EndEngine() {
		if (GetMainWindow()) {
			delete GetMainWindow();
		}
		if (GetMainShader()) {
			GetMainShader()->ClearShader();
			delete GetMainShader();
		}
		if (GetMainCamera()) {
			delete GetMainCamera();
		}
	}

	void Coco2::Coco2_ClearWindow(float redColour, float greenColour, float blueColour) {
		GetMainWindow()->ClearWindow(redColour, greenColour, blueColour);
	}

	void Coco2::Coco2_SwapBuffers() {
		GetMainWindow()->SwapBuffers();
	}

}