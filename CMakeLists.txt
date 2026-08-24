cmake_minimum_required(VERSION 3.16)

project(project1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB lib "lib/*.cpp")

find_package(SDL3 CONFIG REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(main 
	main.cpp
	${lib}
	)


target_link_libraries(main PRIVATE 
	SDL3::SDL3
	!${OpenCV_LIBS}
	)
