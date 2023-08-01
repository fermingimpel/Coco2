#ifndef GAMEPLAYSTATICS_H
#define GAMEPLAYSTATICS_H


namespace Coco2Engine {
	class Camera;
	class Shader;
	class Window;

	extern void SetMainCamera(Camera* Cam);
	extern void SetMainShader(Shader* Shad);
	extern void SetMainWindow(Window* Wind);

	extern Camera* GetMainCamera();
	extern Shader* GetMainShader();
	extern Window* GetMainWindow();
}

#endif