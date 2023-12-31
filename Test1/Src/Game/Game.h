#ifndef GAME_H
#define GAME_H

#include "Coco2/Coco2.h"

using namespace Coco2Engine;

class Game : public Coco2Engine::Coco2 {

private:

protected:
	Triangle* TheTriangle;
	Square* TheSquare;
	Sprite* TheSprite;

	void Update(float DeltaTime) override;

public:

	void Start() override;
	void Play();
	void End() override;

};

#endif