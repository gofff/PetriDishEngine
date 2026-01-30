#include "app/app_settings.h"

#include <fstream>

#include <nlohmann/json.hpp>


namespace petri::app {

using json = nlohmann::json;

void from_json(const json& j, WindowSettings& s) {
	if (j.contains(skeys::kwFullscreen)) {
		j.at(skeys::kwFullscreen).get_to(s.isFullscreen);
	}
	if (j.contains(skeys::kwHeight)) {
		j.at(skeys::kwHeight).get_to(s.height);
	}
	if (j.contains(skeys::kwWidth)) {
		j.at(skeys::kwWidth).get_to(s.width);
	}
	if (j.contains(skeys::kwVsync)) {
		j.at(skeys::kwVsync).get_to(s.vsyncEnabled);
	}
	if (j.contains(skeys::kwTitle)) {
		j.at(skeys::kwTitle).get_to(s.title);
	}
}

void from_json(const json& j, AppSettings& s) {
	if (j.contains(skeys::kaMode)) {
		j.at(skeys::kaMode).get_to(s.mode);
	}

	if (j.contains(skeys::kWindowHeader)) {
		j.at(skeys::kWindowHeader).get_to(s.windowSettings);
	}
}

AppSettings LoadSettings(const std::string& path)
{
	AppSettings settings;

	std::ifstream file(path);
	json j;
	file >> j;
	j.get_to(settings);

	return settings;
}

} // namespace petri::app

