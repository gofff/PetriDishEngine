#include "engine/engine.h"

#include <iostream>


namespace petri::engine {
void Engine::Init()
{
	world_.Init();
}

void Engine::Tick()
{
	time_.Update();
	update(time_.GetDeltaSeconds());
	render();
}

void Engine::update(float dt)
{
	std::cout << "Engine update: " << dt << std::endl;
	world_.Tick(dt);

}

void Engine::render()
{
}

} // namespace petri::engine