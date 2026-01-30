#ifndef PETRI_DISH_ENGINE_TIME_H
#define PETRI_DISH_ENGINE_TIME_H

#include <chrono>


namespace petri::engine {

using Clock = std::chrono::steady_clock;

class Time {
public:
	Time();

	void Update();

	double GetDeltaSeconds() const { return deltaSeconds_; }
	double GetElapsedSeconds() const { return elapsedSeconds_; }
	double GetTimeScale() const { return timeScale_; }
	bool IsPaused() const { return isPaused_; }

	void SetScale(double scale) { timeScale_ = scale; }
	void SetPaused(bool isPaused) { isPaused_ = isPaused; }

private:
	// Measured time
	Clock::time_point lastTick_;
	// Frame delta
	double deltaSeconds_ = 0.0;
	// Total simulation time
	double elapsedSeconds_ = 0.0;
	// Fast-forward / slow-mo
	double timeScale_ = 1.0;
	// For returning zero-delta without stopping clock
	bool isPaused_ = false;
};

} // namespace petri::engine

#endif // PETRI_DISH_ENGINE_TIME_H