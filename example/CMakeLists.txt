cmake_minimum_required(VERSION 3.10)

project(example)

# Add the executable for the example
add_executable(example main.cpp)

# Link the example executable with the library
target_link_libraries(example PRIVATE vigine)

# Include directories
target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/include)