cmake_minimum_required( VERSION 3.5 )
project( tutorial_project )

# The version number
set( tutorial_project_VERSION_MAJOR 1 )
set( tutorial_project_VERSION_MINOR 0 )

# configure a header file to pass some of the CMake setting to the source code
configure_file(
    "${PROJECT_SOURCE_DIR}/tutorial_project_config.h.in"
    "${PROJECT_BINARY_DIR}/tutorial_project_config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable( tutorial tutorial.cpp) # you will found find tutorial at build/tutorial_project
