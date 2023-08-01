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
	TheTriangle->LoadTexture("res/Art/2D", "theolean.jpg");
}

void Game::Update(float DeltaTime) {
	Coco2_ClearWindow(0.15, 0.15, 1.0f);

	//TheTriangle->SetEntityPosition(TheTriangle->GetEntityPosition() + Vector3(0.01f, 0, 0));
	TheTriangle->SetEntityRotation(TheTriangle->GetEntityRotationEuler() + Vector3(0, 0, 90 * DeltaTime));

	TheTriangle->Draw();
	//TheSquare->Draw();

	Coco2_SwapBuffers();
}

void Game::End() {
	Coco2_EndEngine();

	delete TheSquare;
	delete TheTriangle;
}
