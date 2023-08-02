#ifndef GAMEPLAYSTATICS_H
#define GAMEPLAYSTATICS_H


namespace Coco2Engine {
	class Camera;
	class Shader;
	class Window;

	extern void Coco2_SetMainCamera(Camera* Cam);
	extern void Coco2_SetMainShader(Shader* Shad);
	extern void Coco2_SetMainWindow(Window* Wind);

	extern Camera* Coco2_GetMainCamera();
	extern Shader* Coco2_GetMainShader();
	extern Window* Coco2_GetMainWindow();
}

#endif