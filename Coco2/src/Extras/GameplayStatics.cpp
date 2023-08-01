#include "GameplayStatics.h"

#include "Camera/Camera.h"
#include "Shader/Shader.h"
#include "Window/Window.h"

namespace Coco2Engine {

	Camera* MainCamera = nullptr;
	Shader* MainShader = nullptr;
	Window* MainWindow = nullptr;


	void SetMainCamera(Camera* Cam) {
		MainCamera = Cam;
	}
	void SetMainShader(Shader* Shad) {
		MainShader = Shad;
	}
	void SetMainWindow(Window* Wind) {
		MainWindow = Wind;
	}
	Camera* GetMainCamera() {
		return MainCamera;
	}
	Shader* GetMainShader() {
		return MainShader;
	}
	Window* GetMainWindow() {
		return MainWindow;
	}
}