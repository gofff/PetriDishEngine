#include "app/window.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "app/app_settings.h"


namespace petri::app {

GlfwContext::GlfwContext() {
	if (!glfwInit()) {
		// TODO! Change abort to safer option
		std::cerr << "Failed to initialize GLFW\n";
		std::abort();
	}
}

GlfwContext::~GlfwContext() {
	glfwTerminate();
}

Window::Window()
	: glWindow_(nullptr, glfwDestroyWindow)
{}

bool Window::Create(const WindowSettings& settings) {
	// OpenGL 3.3 Core — portable baseline
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// Capture monitor settings
	int width = settings.width;
	int height = settings.height;
	if (settings.isFullscreen) {
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		if (monitor) {
			const GLFWvidmode* mode = glfwGetVideoMode(monitor);
			if (mode) {
				width = mode->width;
				height = mode->height;
			}
			else {
				std::cerr << "Failed to get video mod from monitor. Switch to default\n";
			}
		}
		else {
			std::cerr << "Failed to get monitor. Switch to default\n";
		}
	}

	GLFWwindow* rawWindow = glfwCreateWindow(
		width,
		height,
		settings.title.c_str(),
		nullptr, nullptr
	);

	if (rawWindow == nullptr) {
		std::cerr << "Failed to create GLFW window\n";
		return false;
	}
	glWindow_.reset(rawWindow);

	glfwMakeContextCurrent(glWindow_.get());

	if (!gladLoadGLLoader(
		reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
		std::cerr << "Failed to initialize GLAD\n";
		return false;
	}

	glfwSwapInterval(settings.vsyncEnabled ? 1 : 0);

	return true;
}

void Window::PollEvents() {
	glfwPollEvents();
}

void Window::SwapBuffers() {
	glfwSwapBuffers(glWindow_.get());
}

bool Window::ShouldClose() const {
	return glfwWindowShouldClose(glWindow_.get());
}

void Window::ClearColor()
{
	glClearColor(0.08f, 0.1f, 0.14f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace window
