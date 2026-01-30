set(APP_SOURCES
    time.cc
)

set(APP_HEADERS
    ${PROJECT_SOURCE_DIR}/include/engine/time.h
)

add_library(engine STATIC
    ${APP_SOURCES}
    ${APP_HEADERS}
)

target_include_directories(engine PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

#target_link_libraries(engine_app PRIVATE
#)
