cmake_minimum_required(VERSION 3.20)

project(flappy VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(fmt REQUIRED)

include(cmake/fetchJson.cmake)

set(RESOURCE "${CMAKE_CURRENT_SOURCE_DIR}/resources/")
set(FONT "${CMAKE_CURRENT_SOURCE_DIR}/resources/fonts/")
set(SPRITE "${CMAKE_CURRENT_SOURCE_DIR}/resources/sprites/")

add_executable(flappy)

add_subdirectory(src)
