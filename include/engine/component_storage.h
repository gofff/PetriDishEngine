#ifndef PETRI_DISH_ENGINE_COMPONENT_STORAGE_H
#define PETRI_DISH_ENGINE_COMPONENT_STORAGE_H

#include <cstdint>
#include <vector>

namespace petri::engine {

enum class ComponentId : uint8_t {
	CI_Position,
	CI_Velocity,
	CI_Size,
	CI_Energy,

	CI_Count
};

template<typename T>
struct ComponentTraits;

// -----------------------------
// Position
// -----------------------------
struct PositionComponent {
	std::vector<float> x;
	std::vector<float> y;
};

template<>
struct ComponentTraits<PositionComponent> {
	static constexpr ComponentId cId = ComponentId::CI_Position;
};

// -----------------------------
// Velocity
// -----------------------------

struct VelocityComponent {
	std::vector<float> x;
	std::vector<float> y;
};

template<>
struct ComponentTraits<VelocityComponent> {
	static constexpr ComponentId cId = ComponentId::CI_Velocity;
};

// -----------------------------
// Size
// -----------------------------

struct SizeComponent {
	std::vector<float> radius;
};

template<>
struct ComponentTraits<SizeComponent> {
	static constexpr ComponentId cId = ComponentId::CI_Size;
};

// -----------------------------
// Energy
// -----------------------------

struct EnergyComponent {
	std::vector<float> value;
};

template<>
struct ComponentTraits<EnergyComponent> {
	static constexpr ComponentId cId = ComponentId::CI_Energy;
};

// -----------------------------
// Storage
// -----------------------------

class ComponentStorage {
public:
	template<typename T>
	T& Get();

	template<typename T>
	const T& Get() const;
private:
	PositionComponent position_;
	VelocityComponent velocity_;
	SizeComponent size_;
	EnergyComponent energy_;
};

// Workaround to not hit immediatelly static_assert in Get()
template<typename>
inline constexpr bool AlwaysFalse_v = false;

template<typename T>
inline const T& ComponentStorage::Get() const
{
	constexpr ComponentId id = ComponentTraits<T>::cId;
	if constexpr (id == ComponentId::CI_Position) {
		return position_;
	}
	else if constexpr (id == ComponentId::CI_Velocity) {
		return velocity_;
	}
	else if constexpr (id == ComponentId::CI_Size) {
		return size_;
	}
	else if constexpr (id == ComponentId::CI_Energy) {
		return energy_;
	}
	else {
		static_assert(AlwaysFalse_v<T>	, "Trying to get Unsopported Component");
	}
}

template<typename T>
inline T& ComponentStorage::Get()
{
	// Try to fire me from my hobby
	return const_cast<T&>(
		static_cast<const ComponentStorage*>(this)->Get<T>());
}

} // namespace petri::engine

#endif // PETRI_DISH_ENGINE_COMPONENT_STORAGE_H