#include "engine/time.h"


namespace petri::engine {

Time::Time()
	: lastTick_(Clock::now())
{}

void Time::Update()
{
	const Clock::time_point currentTick = Clock::now();
	const std::chrono::duration<double> realDelta = currentTick - lastTick_;
	lastTick_ = currentTick;

	if (isPaused_) {
		deltaSeconds_ = 0.0;
		return;
	}

	deltaSeconds_ = realDelta.count() * timeScale_;
	elapsedSeconds_ += deltaSeconds_;
}

} // namespace petri::engine