#ifndef PETRI_DISH_ENGINE_ENGINE_H
#define PETRI_DISH_ENGINE_ENGINE_H

#include "engine/time.h"
#include "engine/world.h"

namespace petri::engine {

class Time;

class Engine {
public:
	void Init();
	void Tick();

private:
	void update(float dt);
	void render();

	World world_;
	Time time_;
};

} // namespace petri::engine

#endif // PETRI_DISH_ENGINE_ENGINE_H