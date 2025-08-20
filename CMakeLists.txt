cmake_minimum_required(VERSION 3.15)
project(Chess LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(raylib 5.0 QUIET)

if (NOT raylib_FOUND)
    message(STATUS "raylib not found, using submodule...")
    add_subdirectory(include/raylib)
endif()


file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS src/*.c)
add_executable(${PROJECT_NAME} ${GAME_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} raylib)

file(COPY asset DESTINATION ${CMAKE_BINARY_DIR})
