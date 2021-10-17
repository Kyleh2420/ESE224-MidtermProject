cmake_minimum_required(VERSION 3.11)

project (
    MidtermProject
    VERSION 0.1
    DESCRIPTION "Experimenting with CMake on the Midterm Project"
)

include_directories("include")
include_directories("src")


add_library(enemy STATIC
    "src/enemy.cpp"
    "include/enemy.h"
)

add_executable(midterm "src/game.cpp")