cmake_minimum_required(VERSION 3.11-3.18)

project(main)

add_executable(main game.cpp)
#We need all the libraries and files
target_link_libraries(main PRIVATE enemy)
target_link_libraries(main PRIVATE fileOperations)
target_link_libraries(main PRIVATE Player)
target_link_libraries(main PRIVATE scoreboard)
target_link_libraries(main PRIVATE Weapon)

#Tell the C++ Compiler to use C++20 Features
target_compile_features(main PUBLIC cxx_std_20)