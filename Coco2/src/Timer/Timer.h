#ifndef TIMER_H
#define TIMER_H

namespace Coco2Engine {

	class Timer {
	public:
		static void UpdateDeltaTime();
		static float GetDeltaTime();
	};

}

#endif