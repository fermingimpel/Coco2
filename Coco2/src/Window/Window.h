#ifndef WINDOW_H
#define WINDOW_H
	
struct GLFWwindow;
struct GLFWmonitor;

namespace Coco2Engine {

	class Window {

	private:

	protected:

	public:
		GLFWwindow* MainWindow;

		Window();

		bool CreateWindow(int width, int height, const char* windowName, GLFWmonitor* fullScreen);
		void InitWindow();
		void DestroyWindow();
		bool CheckIfWindowIsOpen();
		void ClearWindow(float r, float g, float b);
		void SwapBuffers();
	};

}

#endif