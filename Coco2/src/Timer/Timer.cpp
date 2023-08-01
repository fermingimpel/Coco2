#include "Timer.h"

#include <time.h>

namespace Coco2Engine {

	double oldT = clock();
	void Timer::DeltaTime(float& time) {
		double t = clock();
		float dt = (float)((t - oldT) / 1000.0f);
		oldT = t;
		time = dt;
	}

}