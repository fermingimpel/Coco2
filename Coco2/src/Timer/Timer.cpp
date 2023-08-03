#include "Timer.h"

#include <time.h>

namespace Coco2Engine {

	float oldTime = clock();
	float dt = 0;
	void Timer::UpdateDeltaTime() {
		double t = clock();
		dt = (float)((t - oldTime) / 1000.0f);
		oldTime = t;
	}

	float Timer::GetDeltaTime() {
		return dt;
	}

}