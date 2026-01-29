# Changelog

## [0.1.0] – Initial engine bootstrap

### Added
- Application bootstrap with clear lifecycle (`App`)
- Cross-platform window creation using GLFW
- OpenGL context initialization via GLAD
- Fullscreen and windowed modes driven by configuration
- JSON-based settings system with typed `AppSettings` and `WindowSettings`
- Scalable settings loader with clean separation of concerns
- Deterministic startup via external configuration file