cmake_minimum_required(VERSION 3.24)
project(eprem LANGUAGES C)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules/")

add_subdirectory(src)
