#include "app/app.h"

#include <iostream>
#include <string>

#include "app/window.h"
#include "app/app_settings.h"


namespace petri {

int App::Run() {
	std::cout << "PetriDishEngine starting..." << std::endl;
	app::AppSettings settings = app::LoadSettings(settingsPath_);

	app::GlfwContext glfw;
	app::Window window;
	
	if (!window.Create(settings.windowSettings)) {
		return -1;
	}
	while (!window.ShouldClose())
	{
		window.ClearColor();
		window.SwapBuffers();
		window.PollEvents();
	}
	return 0;
}

} // namespace petri