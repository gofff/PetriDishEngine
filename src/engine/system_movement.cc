#include "engine/systems.h"

#include <cassert>
#include <iostream>

namespace petri::engine {

void MakeMovement(ComponentStorage& components, float dt) {
	PositionComponent& pos = components.Get<PositionComponent>();
	const VelocityComponent& vel = components.Get<VelocityComponent>();
	assert(pos.x.size() == vel.x.size() && pos.y.size() == vel.y.size());
	std::cout << "Make movement for: " << pos.x.size() << " entities" << std::endl;
	for (size_t i = 0; i < pos.x.size(); ++i) {
		pos.x[i] += vel.x[i] * dt;
		pos.y[i] += vel.y[i] * dt;
	}
}

} // namespace petri::engine