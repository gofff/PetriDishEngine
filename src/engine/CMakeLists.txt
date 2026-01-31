set(APP_SOURCES
    time.cc
    engine.cc
    world.cc
    entity_storage.cc
    component_storage.cc
)

set(SYSTEM_SOURCES
    system_movement.cc
)

set(APP_HEADERS
    ${PROJECT_SOURCE_DIR}/include/engine/time.h
    ${PROJECT_SOURCE_DIR}/include/engine/engine.h
    ${PROJECT_SOURCE_DIR}/include/engine/world.h
    ${PROJECT_SOURCE_DIR}/include/engine/entity_storage.h
    ${PROJECT_SOURCE_DIR}/include/engine/component_storage.h
    ${PROJECT_SOURCE_DIR}/include/engine/systems.h
)

add_library(engine STATIC
    ${APP_SOURCES}
    ${SYSTEM_SOURCES}
    ${APP_HEADERS}
)

target_include_directories(engine PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

#target_link_libraries(engine_app PRIVATE
#)
