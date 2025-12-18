cmake_minimum_required(VERSION 4.1)
project(map)

set(CMAKE_CXX_STANDARD 20)

add_executable(map main.cpp)

add_library(MapLib)

target_sources(MapLib
        PRIVATE
            map/map.cpp

        PUBLIC
            FILE_SET HEADERS
            BASE_DIRS
                map
            FILES
                map/map.h
)

target_link_libraries(map
        PRIVATE
            MapLib
)

