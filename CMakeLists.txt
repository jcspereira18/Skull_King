cmake_minimum_required(VERSION 3.15)

set(This Example)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
   include/Example.hpp
   include/game.h
   include/player.h
   include/deck.h
   include/card.h
)
set(Sources
   src/Example.cpp
   src/game.cpp
   src/player.cpp
   src/deck.cpp
   src/card.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(tests)