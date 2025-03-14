cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME vigine)

# Set the project name
project(${PROJECT_NAME})

# Add an executable with the source files
add_executable(${PROJECT_NAME} src/main.cpp)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)