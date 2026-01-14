cmake_minimum_required(VERSION 4.1)
project(map)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Red-Black-Tree-Cpp)

add_library(MapLib INTERFACE)

target_sources(MapLib
        PRIVATE
        include/map.tpp
        include/pair.tpp
        PUBLIC
            FILE_SET HEADERS
            BASE_DIRS
                include
            FILES
        include/map.h
        include/pair.h
        include/score_traits.h
)

target_link_libraries(MapLib INTERFACE RedBlackTreeLibrary)

add_executable(map main.cpp)

target_link_libraries(map
        PRIVATE
            MapLib
)