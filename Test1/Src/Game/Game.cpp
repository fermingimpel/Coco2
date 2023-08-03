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
	TheTriangle->SetEntityPosition(Vector3(2, 0, -7));

	TheSquare = new Square();
	TheSquare->LoadTexture("res/Art/2D", "theolean.jpg");
	TheSquare->SetEntityPosition(Vector3(-2, 0, -7));
	//TheSquare->SetEntityRotation(Vector3(0, 90, 0));

	TheSprite = new Sprite("res/Art/2D", "sprite2.png");
	TheSprite->CreateNewAnimation(8, 4, 4,0.1f, 8, "RunDown");
	TheSprite->SetEntityPosition(Vector3(0, 0, -3));

}

void Game::Update(float DeltaTime) {
	Coco2_ClearWindow(0.15, 0.15, 1.0f);

	//TheTriangle->SetEntityPosition(TheTriangle->GetEntityPosition() + Vector3(0.01f, 0, 0));
	//TheTriangle->SetEntityRotation(TheTriangle->GetEntityRotationEuler() + Vector3(0, 0, 90 * DeltaTime));
	//TheSquare->SetEntityRotation(TheSquare->GetEntityRotationEuler() + Vector3(0, 90 * DeltaTime, 0));

	TheTriangle->Draw();
	TheSquare->Draw();

	TheSprite->Draw();

	if (GetKeyDown(Keycode::A)) {
		Coco2_GetMainCamera()->AddEntityPosition(Coco2_GetMainCamera()->GetEntityRightVector() * DeltaTime * 3.0f);
	}
	else if (GetKeyDown(Keycode::D)) {
		Coco2_GetMainCamera()->AddEntityPosition(-Coco2_GetMainCamera()->GetEntityRightVector() * DeltaTime * 3.0f);
	}

	if (GetKeyDown(Keycode::W)) {
		Coco2_GetMainCamera()->AddEntityPosition(Coco2_GetMainCamera()->GetEntityForwardVector() * DeltaTime * 3.0f);
	}
	else if (GetKeyDown(Keycode::S)) {
		Coco2_GetMainCamera()->AddEntityPosition(- Coco2_GetMainCamera()->GetEntityForwardVector() * DeltaTime * 3.0f);
	}

	if (GetKeyDown(Keycode::Q)) {
		Coco2_GetMainCamera()->AddEntityRotation(Vector3(0, 90 * DeltaTime, 0));
	}
	else if (GetKeyDown(Keycode::E)) {
		Coco2_GetMainCamera()->AddEntityRotation(Vector3(0, -90 * DeltaTime, 0));

	}


	Coco2_SwapBuffers();
}

void Game::End() {
	Coco2_EndEngine();

	delete TheSquare;
	delete TheTriangle;
	delete TheSprite;
}
