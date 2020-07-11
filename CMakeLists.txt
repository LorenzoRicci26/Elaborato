cmake_minimum_required(VERSION 3.13)

project(Elaborato)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS system window graphics)
add_executable(Elaborato main.cpp GameCharacter.cpp GameCharacter.h Map.cpp Map.h Subject.h Observer.h Display.h stlastar.h fsa.h)

target_link_libraries(Elaborato sfml-system sfml-window sfml-graphics)

