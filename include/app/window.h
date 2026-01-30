#ifndef PETRI_DISH_ENGINE_APP_WINDOW_H
#define PETRI_DISH_ENGINE_APP_WINDOW_H

#include <memory>
#include <string>


struct GLFWwindow;

namespace petri::app {

struct WindowSettings;

class GlfwContext {
public:
	GlfwContext();
	GlfwContext(const GlfwContext&) = delete;
	GlfwContext& operator=(GlfwContext&) = delete;
	~GlfwContext();
};

class Window {
public:
	Window();
	// You see it earlier then unique_ptr in private. I know this is useless there
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	bool Create(const WindowSettings& settings);
	void PollEvents();
	void SwapBuffers();
	bool ShouldClose() const;

	void ClearColor();

private:
	using WindowDeleter = void (*)(GLFWwindow*);
	std::unique_ptr<GLFWwindow, WindowDeleter> glWindow_;
};

} // namespace petri::app

#endif // PETRI_DISH_ENGINE_APP_WINDOW_H