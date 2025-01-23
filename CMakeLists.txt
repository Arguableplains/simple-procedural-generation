cmake_minimum_required(VERSION 3.0.0)

project(pg_simple VERSION 0.1.0)
file(GLOB_RECURSE SRC_FILES ./src/*cpp)
add_executable(pg_simple src/main.cpp ${SRC_FILES})

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

target_include_directories(pg_simple PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(pg_simple glfw GL GLEW)
