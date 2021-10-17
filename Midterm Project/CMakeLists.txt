cmake_minimum_required(VERSION 3.11-3.18)

project (
    Midterm Project
    VERSION 0.1
    DESCRIPTION "Experimenting with CMake on the Midterm Project"
)

add_subdirectory(Game) #Look in src subdirectory for CMakeLists.txt 
add_subdirectory(apps)