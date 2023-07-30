#ifndef COCO2_H
#define COCO2_H

#include "Extras/Coco2Maths.h"
#include "Shader/Shader.h"
#include "Entities/Shapes/2D/Triangle/Triangle.h"

namespace Coco2Engine {

class Window;

	class Coco2
	{

	private:
		Window* MainWindow = nullptr;
		Shader* MainShader = nullptr;
	protected:
		Coco2();

		bool Coco2_StartEngine(int width, int height, const char* windowName);
		void Coco2_UpdateEngine();
		void Coco2_EndEngine();

		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void End() = 0;

		void Coco2_ClearWindow(float redColour, float greenColour, float  blueColour);
		void Coco2_SwapBuffers();
	public:

	};

}

#endif