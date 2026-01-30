# Changelog

## [0.1.0e] – Initial Engine bootstrap
- Time counter with managing `DeltaSeconds`, `ElapsedSeconds`, `TimeScale`, `IsPaused`
- Engine class bootstrap with Update() and managing Time object

## [0.1.0] – Initial App bootstrap

### Added
- Application bootstrap with clear lifecycle (`App`)
- Cross-platform window creation using GLFW
- OpenGL context initialization via GLAD
- Fullscreen and windowed modes driven by configuration
- JSON-based settings system with typed `AppSettings` and `WindowSettings`
- Scalable settings loader with clean separation of concerns
- Deterministic startup via external configuration file