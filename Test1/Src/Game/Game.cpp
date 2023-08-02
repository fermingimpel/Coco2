#include "Game.h"

#include <iostream>

using namespace Coco2Engine;

void Game::Play() {
	Coco2_UpdateEngine();
}

void Game::Start() {
	Coco2_StartEngine(800, 600, "Coco2");

	TheTriangle = new Triangle();
	TheTriangle->LoadTexture("res/Art/2D", "theolean.jpg");
	TheTriangle->SetEntityPosition(Vector3(2, 0, -5));

	TheSquare = new Square();
	TheSquare->LoadTexture("res/Art/2D", "theolean.jpg");
	TheSquare->SetEntityPosition(Vector3(-2, 0, -5));
	TheSquare->SetEntityRotation(Vector3(0, 90, 0));

}

void Game::Update(float DeltaTime) {
	Coco2_ClearWindow(0.15, 0.15, 1.0f);

	//TheTriangle->SetEntityPosition(TheTriangle->GetEntityPosition() + Vector3(0.01f, 0, 0));
	TheTriangle->SetEntityRotation(TheTriangle->GetEntityRotationEuler() + Vector3(0, 0, 90 * DeltaTime));
	TheSquare->SetEntityRotation(TheSquare->GetEntityRotationEuler() + Vector3(0, 90 * DeltaTime, 0));

	TheTriangle->Draw();
	TheSquare->Draw();

	Coco2_GetMainCamera()->SetEntityPosition(Coco2_GetMainCamera()->GetEntityPosition() + Vector3(DeltaTime,0,0));

	Coco2_SwapBuffers();
}

void Game::End() {
	Coco2_EndEngine();

	delete TheSquare;
	delete TheTriangle;
}
