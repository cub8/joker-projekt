cmake_minimum_required(VERSION 3.0.0)
project(WindowTest VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable( 
    WindowTest main.cpp 
    src/app/app.cpp 
    src/perlin_utilities/perlin_noise_generator.cpp
    src/visualization/noise_drawer.cpp
    src/app/gui/gui.cpp
    src/app/gui/button.cpp
    src/app/gui/widget.cpp
    )

find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)
target_link_libraries(WindowTest sfml-graphics sfml-window)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
