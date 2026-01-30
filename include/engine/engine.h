#ifndef PETRI_DISH_ENGINE_ENGINE_H
#define PETRI_DISH_ENGINE_ENGINE_H

#include "engine/time.h"

namespace petri::engine {

class Engine {
public:
	void Tick();

private:
	void update(double dt);
	void render();

	Time time_;
};

} // namespace petri::engine

#endif // PETRI_DISH_ENGINE_ENGINE_H