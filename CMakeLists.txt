# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

# Set the project name
project(brogue VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the libtcod package
find_package(libtcod CONFIG REQUIRED)

# Include directories (if needed)
include_directories(include)

# Find all source files and header files in the src directory
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h" "src/*.hpp")

# Add the executable
add_executable(MyExecutable ${SOURCES} ${HEADERS})

# Link against the libtcod library
target_link_libraries(MyExecutable PRIVATE libtcod::libtcod)