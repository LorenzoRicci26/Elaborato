cmake_minimum_required(VERSION 3.13)
project(Elaborato)

set(CMAKE_CXX_STANDARD 11)

add_executable(Elaborato main.cpp GameCharacter.cpp GameCharacter.h Map.cpp Map.h Subject.h Observer.h Display.h)