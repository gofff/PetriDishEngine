#ifndef PETRI_DISH_ENGINE_APP_APP_SETTINGS_H
#define PETRI_DISH_ENGINE_APP_APP_SETTINGS_H

#include <string>

namespace petri::app {

// -----------------------------
// Window Settings
// -----------------------------
namespace skeys {
	inline constexpr std::string_view kWindowHeader = "Window";
	inline constexpr std::string_view kwFullscreen = "enable_fullscreen";
	inline constexpr std::string_view kwHeight = "height";
	inline constexpr std::string_view kwWidth = "width";
	inline constexpr std::string_view kwVsync = "enable_vsync";
	inline constexpr std::string_view kwTitle = "title";
}
struct WindowSettings {
	bool isFullscreen = true;
	int width = 800;
	int height = 600;
	bool vsyncEnabled = true;
	std::string title = "PetriDishEngine";
};

// -----------------------------
// App Settings
// -----------------------------
namespace skeys {
	inline constexpr std::string_view kaMode = "mode";
}
struct AppSettings {
	int mode = 0;
	WindowSettings windowSettings;
};

AppSettings LoadSettings(const std::string& path);

} // namespace petri::app

#endif // PETRI_DISH_ENGINE_APP_APP_SETTINGS_H