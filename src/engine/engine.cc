#include "engine/engine.h"

#include <iostream>

namespace petri::engine {

void Engine::Tick()
{
	time_.Update();
	update(time_.GetDeltaSeconds());
	render();
}

void Engine::update(double dt)
{
	std::cout << "Engine update: " << dt << std::endl;
}

void Engine::render()
{
}

} // namespace petri::engine