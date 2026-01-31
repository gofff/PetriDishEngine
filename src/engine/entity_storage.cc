#include "engine/entity_storage.h"

#include <iostream>
#include <cassert>

namespace petri::engine {


void EntityStorage::Create()
{
	uint32_t id = 0;
	uint32_t generation = 0;
	if (!freeIds_.empty()) {
		id = freeIds_.back();
		freeIds_.pop_back();
		generation = ++generations_[id];
	}
	else {
		assert(generations_.size() == denseEntities_.size());
		// denseEntites_ is a last true to adjust sizes
		id = static_cast<uint32_t>(denseEntities_.size());
		generation = 0;
		generations_.push_back(0);
		idToDense_.push_back(0);
	}

	idToDense_[id] = denseEntities_.size();
	denseEntities_.emplace_back(Entity{ id, generation });
}




} // namespace petri::engine