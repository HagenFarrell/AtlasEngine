cmake_minimum_required(VERSION 3.12)
project(MyVulkanEngine)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE ENGINE_SOURCES src/*.cpp)
file(GLOB_RECURSE ENGINE_HEADERS src/*.h)

# Define the executable
add_executable(MyVulkanEngine ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Find Vulkan
find_package(Vulkan REQUIRED)
target_link_libraries(MyVulkanEngine PRIVATE Vulkan::Vulkan)

# GLFW paths
set(GLFW_INCLUDE_DIR "C:/Users/Hagen/Documents/Visual Studio 2022/Libraries/glfw-3.4.bin.WIN64/include")
set(GLFW_LIBRARY_DIR "C:/Users/Hagen/Documents/Visual Studio 2022/Libraries/glfw-3.4.bin.WIN64/lib-vc2022")

# Debug GLFW paths
message(STATUS "GLFW_INCLUDE_DIR: ${GLFW_INCLUDE_DIR}")
message(STATUS "GLFW_LIBRARY_DIR: ${GLFW_LIBRARY_DIR}")

# Include GLFW headers
include_directories(${GLFW_INCLUDE_DIR})

# Link GLFW library using full path
target_link_libraries(MyVulkanEngine PRIVATE "${GLFW_LIBRARY_DIR}/glfw3.lib")

# Include directories
target_include_directories(MyVulkanEngine PRIVATE src)

# Debugging flags
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
    message(STATUS "Debug mode enabled.")
endif()

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)