include(FetchContent)
cmake_minimum_required(VERSION 3.17)

project(ibeel)

set(CMAKE_CXX_STANDARD 17)

FetchContent_Declare(
        imgui-glfw-glad-glm
        GIT_REPOSITORY https://github.com/cmmw/imgui-glfw-glad-glm.git
)
FetchContent_MakeAvailable(imgui-glfw-glad-glm)

# Fetch the stb library
FetchContent_Declare(
		stb
		GIT_REPOSITORY https://github.com/nothings/stb.git)
FetchContent_MakeAvailable(stb)
include_directories(${stb_SOURCE_DIR})

add_executable(
		ibeel
		source/main.cpp
		source/ibeel.hpp
		source/ibeel.cpp)

target_link_libraries(
		ibeel
		glfw
		glad
        glm
		imgui)