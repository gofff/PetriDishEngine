#include "engine/world.h"

#include <iostream>

#include "engine/systems.h"

namespace petri::engine {

void World::Init()
{
}

void World::Tick(float dt)
{
	std::cout << "World tick: " << dt << std::endl;
	MakeMovement(componentStorage_, dt);
}

} // namespace petri::engine