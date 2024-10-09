# CMake minimum version and project name
cmake_minimum_required(VERSION 3.10)
project(BBE)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
set(SOURCES src/main.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Google Test setup
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add test executable
add_executable(
  unit_tests
  # Add other source files needed for tests
  tests/sample_test.cpp
)

# Link test executable with gtest and gtest_main
target_link_libraries(
  unit_tests
  GTest::gtest_main
)

# Include Google Test module
include(GoogleTest)
gtest_discover_tests(unit_tests)