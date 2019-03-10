cmake_minimum_required(VERSION 3.0)
project(SolutionViewer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to create code from Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set(solutionviewer_SRC
  src/main.cpp
  src/mainwindow.cpp
  src/mesh.cpp
  src/object.cpp
  src/solutionviewer.cpp
)

# Tell CMake to create the helloworld executable
add_executable(solutionviewer ${solutionviewer_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(solutionviewer Qt5::Widgets)

add_custom_command(TARGET solutionviewer POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/textures $<TARGET_FILE_DIR:solutionviewer>)
                       
add_custom_command(TARGET solutionviewer POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:solutionviewer>)
