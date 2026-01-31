#ifndef PETRI_DISH_ENGINE_WORLD_H
#define PETRI_DISH_ENGINE_WORLD_H

#include "engine/entity_storage.h"
#include "engine/component_storage.h"

namespace petri::engine {

class World {
public:
	void Init();

	void Tick(float dt);

private:
	EntityStorage entityStorage_;
	ComponentStorage componentStorage_;
};


} // namespace petri::engine
#endif // PETRI_DISH_ENGINE_WORLD_H