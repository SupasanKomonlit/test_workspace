cmake_minimum_required( VERSION 3.5 )
project( import_project )

find_package( ament_cmake REQUIRED )
find_package( tutorial_project REQUIRED COMPONENT)

set( tutorial_project_dir ${tutorial_project_DIR})
set( tutorial_project_include_dir ${tutorial_project_INCLUDE_DIRS})
set( tutorial_project_library_dir ${tutorial_project_LIBRARY_DIRS})

configure_file(
    "${PROJECT_SOURCE_DIR}/import_project_configure.hpp.in"
    "${PROJECT_BINARY_DIR}/import_project_configure.hpp" 
)

include_directories(
    "${PROJECT_BINARY_DIR}"
    "${tutorial_project_INCLUDE_DIRS}"
)

add_executable( import_file import_file.cpp)

install( TARGETS import_file DESTINATION bin )
install( FILES "${PROJECT_BINARY_DIR}/import_project_configure.hpp" DESTINATION include ) 

ament_package()
