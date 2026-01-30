#ifndef PETRI_DISH_ENGINE_APP_H
#define PETRI_DISH_ENGINE_APP_H

#include <string>


namespace petri {

class App {
public:
	explicit App(std::string settingsPath)
		: settingsPath_(std::move(settingsPath))
	{};

	int Run();
private:
	std::string settingsPath_;
};

} // namespace petri

#endif // PETRI_DISH_ENGINE_APP_H