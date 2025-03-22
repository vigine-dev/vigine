cmake_minimum_required(VERSION 3.10)

set(PROJECT_TEST_NAME unittest)

project(${PROJECT_TEST_NAME})

# ====================== Add Google Test =======================
add_subdirectory(${CMAKE_SOURCE_DIR}/external/googletest ${CMAKE_BINARY_DIR}/googletest)

# ====================== Create Test Executable =======================
add_executable(${PROJECT_TEST_NAME}
    test_vigine.cpp
    component/ComponentManagerTest.cpp
)

# ====================== Link Google Test Libraries =======================
target_link_libraries(${PROJECT_TEST_NAME}
    gtest
    gtest_main
    vigine
)

