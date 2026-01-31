#ifndef PETRI_DISH_ENGINE_SYSTEMS_H
#define PETRI_DISH_ENGINE_SYSTEMS_H

#include "engine/component_storage.h"

namespace petri::engine {

void MakeMovement(ComponentStorage& components, float dt);

} // namespace petri::engine

#endif // PETRI_DISH_ENGINE_SYSTEMS_H