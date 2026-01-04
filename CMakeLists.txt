cmake_minimum_required(VERSION 4.1)
project(include)

set(CMAKE_CXX_STANDARD 20)

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
)

add_executable(map main.cpp)

target_link_libraries(map
        PRIVATE
            MapLib
)