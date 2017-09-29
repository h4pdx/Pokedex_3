cmake_minimum_required(VERSION 3.7)
project(Pokedex)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pokemon.cpp pokemon.h pokedex.cpp pokedex.h)
add_executable(Pokedex ${SOURCE_FILES})