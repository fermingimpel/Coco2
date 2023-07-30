#include "Game.h"

#include <iostream>

using namespace Coco2Engine;

void Game::Play() {
	Coco2_UpdateEngine();
}

void Game::Start() {
	Coco2_StartEngine(800, 600, "Coco2");

	TheTriangle = new Triangle(Coco2_GetShader());
	TheSquare = new Square(Coco2_GetShader());
}

void Game::Update() {
	Coco2_ClearWindow(0.15, 0.15, 1.0f);

	//TheTriangle->Draw();
	TheSquare->Draw();

	Coco2_SwapBuffers();
}

void Game::End() {
	Coco2_EndEngine();

	delete TheSquare;
	delete TheTriangle;
}
