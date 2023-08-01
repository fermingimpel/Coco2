#ifndef COCO2_H
#define COCO2_H

#include "Extras/Coco2Maths.h"
#include "Entities/Shapes/2D/Triangle/Triangle.h"
#include "Entities/Shapes/2D/Square/Square.h"

#include "Timer/Timer.h"

namespace Coco2Engine {

	class Window;
	class Camera;
	class Shader;

	class Coco2 {

	private:
		Window* MainWindow = nullptr;
		Shader* MainShader = nullptr;
		Camera* MainCamera = nullptr;
	protected:
		Coco2();

		bool Coco2_StartEngine(int width, int height, const char* windowName);
		void Coco2_UpdateEngine();
		void Coco2_EndEngine();

		virtual void Start() = 0;
		virtual void Update(float DeltaTime) = 0;
		virtual void End() = 0;

		void Coco2_ClearWindow(float redColour, float greenColour, float  blueColour);
		void Coco2_SwapBuffers();
		Shader* Coco2_GetShader() const {return MainShader;}
	public:

	};

}

#endif