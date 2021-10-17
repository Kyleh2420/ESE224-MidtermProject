cmake_minimum_required(VERSION 3.11-3.18)

project(Game)

add_library(enemy src/enemy.cpp)
add_library(fileOperations src/fileOperations.cpp)
add_library(Player src/Player.cpp)
add_library(scoreboard src/Scoreboard.cpp)
add_library(Weapon src/Weapon.cpp)

#PUBLIC needed to make everything available elsewhere in the project
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}\include)


#Tell compuler to use C++20 features
target_compile_features(Game PUBLIC cxx_std_20)