#ifndef GAME_H
#define GAME_H

#include "Coco2/Coco2.h"

class Game : public Coco2Engine::Coco2{

private:

protected:
	Coco2Engine::Triangle* TheTriangle;

	void Update() override;

public:

	void Start() override;
	void Play();
	void End() override;

};

#endif