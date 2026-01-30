#include "app/app.h"

#include <iostream>
#include <string>

#include "app/window.h"
#include "app/app_settings.h"
#include "engine/engine.h"


namespace petri {

int App::Run() {
	std::cout << "PetriDishEngine starting..." << std::endl;
	app::AppSettings settings = app::LoadSettings(settingsPath_);

	app::GlfwContext glfw;
	app::Window window;
	
	if (!window.Create(settings.windowSettings)) {
		return -1;
	}

	engine::Engine engine;

	while (!window.ShouldClose())
	{
		window.PollEvents();
		engine.Tick();
		window.ClearColor();
		window.SwapBuffers();
	}
	return 0;
}

} // namespace petri