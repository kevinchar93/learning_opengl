cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(OpenGlDemos)

set(CMAKE_CXX_STANDARD 11)

# ------------------------------------------------------------------------------
# Set the variable for the source files
set(SOURCES src/main.cc)

# Create a directory for the build outputs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/release")

# Disable building of docs tests and examples in GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


# ------------------------------------------------------------------------------
# Add GLFW source into the project
add_subdirectory(glfw)


# ------------------------------------------------------------------------------
# Find the required packages needed to work with OpenGL
find_package(OpenGL REQUIRED)
find_package(Glew REQUIRED)


# ------------------------------------------------------------------------------
# Add include directories
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/glfw/include/)
include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${GLEW_INCLUDE_DIRS})

# Add the executables to the project
add_executable(OpenGLDemoCore ${SOURCES})

# Add the link libraries for the project
target_link_libraries(OpenGLDemoCore glfw ${GLEW_LIBRARY} ${OPENGL_gl_LIBRARY})
