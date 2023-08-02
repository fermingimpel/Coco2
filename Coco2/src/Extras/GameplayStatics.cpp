#include "GameplayStatics.h"

#include "Camera/Camera.h"
#include "Shader/Shader.h"
#include "Window/Window.h"

namespace Coco2Engine {

	Camera* MainCamera = nullptr;
	Shader* MainShader = nullptr;
	Window* MainWindow = nullptr;


	void Coco2_SetMainCamera(Camera* Cam) {
		MainCamera = Cam;
	}
	void Coco2_SetMainShader(Shader* Shad) {
		MainShader = Shad;
	}
	void Coco2_SetMainWindow(Window* Wind) {
		MainWindow = Wind;
	}
	Camera* Coco2_GetMainCamera() {
		return MainCamera;
	}
	Shader* Coco2_GetMainShader() {
		return MainShader;
	}
	Window* Coco2_GetMainWindow() {
		return MainWindow;
	}
}