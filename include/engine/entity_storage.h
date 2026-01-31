#ifndef PETRI_DISH_ENGINE_ENTITY_STORAGE_H
#define PETRI_DISH_ENGINE_ENTITY_STORAGE_H

#include <cstdint>
#include <vector>

namespace petri::engine {

struct Entity {
	uint32_t id = 0;
	uint32_t generation = 0;
};

class EntityStorage {
public:
	void Create();



	std::size_t Size() const { return denseEntities_.size(); }

private:
	// Dense array of Entities
	std::vector<Entity> denseEntities_;
	// Mapping between ids and dense array
	std::vector<size_t> idToDense_;
	// Identity managment
	std::vector<uint32_t> generations_;
	// TODO! Research about stack via vector
	std::vector<uint32_t> freeIds_;



};

} // namespace petri::engine

#endif // PETRI_DISH_ENGINE_ENTITY_STORAGE_H