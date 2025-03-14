cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME vigine)

# Set the project name
project(${PROJECT_NAME})

# Set the CMake module path to include the cmake directory
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Find and include glm
find_package(GLM REQUIRED)

# Option to build examples
option(BUILD_EXAMPLES "Build example projects" OFF)

# Add the example project if the option is enabled
if(BUILD_EXAMPLES  AND EXISTS "${CMAKE_SOURCE_DIR}/example/CMakeLists.txt")
    add_subdirectory(example)
endif()

# Add source files
set(SOURCES
    src/vigine.cpp
    # ...додайте інші вихідні файли тут...
)

# Add a library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include ${GLM_INCLUDE_DIRS})

# Install the library and headers
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION ${CMAKE_SOURCE_DIR}/build/include)
