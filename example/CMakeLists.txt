cmake_minimum_required(VERSION 3.10)

set(PROJECT_EXAMPLE_NAME example)

project(${PROJECT_EXAMPLE_NAME})

# Add the executable for the example
add_executable(${PROJECT_EXAMPLE_NAME} main.cpp)

# Link the example executable with the library
target_link_libraries(${PROJECT_EXAMPLE_NAME}
    PRIVATE
    vigine
)

# Include directories
target_include_directories(${PROJECT_EXAMPLE_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
