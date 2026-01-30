set(APP_SOURCES
    app.cc
    window.cc
    app_settings.cc
)

set(APP_HEADERS
    ${PROJECT_SOURCE_DIR}/include/app/app.h
    ${PROJECT_SOURCE_DIR}/include/app/window.h
    ${PROJECT_SOURCE_DIR}/include/app/app_settings.h
)

add_library(engine_app STATIC
    ${APP_SOURCES}
    ${APP_HEADERS}
)

target_include_directories(engine_app PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(engine_app PRIVATE
    glfw
    glad_gl
    OpenGL::GL
    nlohmann_json
    engine
)
