cmake_minimum_required( VERSION 3.5 )
project( tutorial_project )

# The version number
set( tutorial_project_VERSION_MAJOR 1 )
set( tutorial_project_VERSION_MINOR 0 )

option( USE_MY_PUSH_DATA "Use variadic function to push data" ON )

find_package( ament_cmake REQUIRED )

# configure a header file to pass some of the CMake setting to the source code
configure_file(
    "${PROJECT_SOURCE_DIR}/tutorial_project_config.h.in"
    "${PROJECT_BINARY_DIR}/tutorial_project_config_binary.h"
)

include_directories(
    "${PROJECT_BINARY_DIR}"
)
if( USE_MY_PUSH_DATA )
    include_directories( "${PROJECT_SOURCE_DIR}/PushInVector")
    add_subdirectory( PushInVector )
    set( EXTRA_LIBS ${EXTRA_LIBS} PushInVector )
endif( USE_MY_PUSH_DATA )

add_executable( tutorial tutorial.cpp) # you will found find tutorial at build/tutorial_project
target_link_libraries( tutorial ${EXTRA_LIBS} )

ament_export_include_directories( "${PROJECT_SOURCE_DIR}/PushInVector" 
    "${PROJECT_BINARY_DIR}"
)

ament_export_libraries( PushInVector )

install( TARGETS tutorial DESTINATION bin )
install( FILES "${PROJECT_BINARY_DIR}/tutorial_project_config_binary.h" DESTINATION include )

ament_package()
