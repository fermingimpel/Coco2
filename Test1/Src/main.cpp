#include <iostream>

#include "Game/Game.h"

using namespace Coco2Engine;

int main() {

	Game* game = new Game();

	if (game) {

		game->Start();
		game->Play();
		game->End();

		delete game;
	}

	return 0;
}