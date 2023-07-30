#include "Game.h"

#include <iostream>

void Game::Play() {
	Coco2_UpdateEngine();
}

void Game::Start() {
	Coco2_StartEngine(800, 600, "Coco2");

}

void Game::Update() {
	Coco2_ClearWindow(0.15, 0.15, 1.0f);




	Coco2_SwapBuffers();
}

void Game::End() {
	Coco2_EndEngine();
}
