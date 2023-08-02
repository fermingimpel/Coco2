#include "Input.h"

#include <glfw/glfw3.h>

#include "Extras/GameplayStatics.h"
#include "Window/Window.h"

namespace Coco2Engine {

	bool GetKeyDown(Keycode Key) {
		return (glfwGetKey(Coco2_GetMainWindow()->MainWindow, Key) == GLFW_PRESS);
	}

	bool GetKeyUp(Keycode Key) {
		return (glfwGetKey(Coco2_GetMainWindow()->MainWindow, Key) == GLFW_RELEASE);
	}

	bool GetMouseButtonDown(MouseButtons Button) {
		return (glfwGetMouseButton(Coco2_GetMainWindow()->MainWindow, Button) == GLFW_PRESS);
	}

	bool GetMouseButtonUp(MouseButtons Button) {
		return (glfwGetMouseButton(Coco2_GetMainWindow()->MainWindow, Button) == GLFW_RELEASE);
	}

}