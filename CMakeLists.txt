cmake_minimum_required(VERSION 4.1)
project(include)

set(CMAKE_CXX_STANDARD 20)

add_executable(map main.cpp)

add_library(MapLib)

target_sources(MapLib
        PRIVATE
            include/map.cpp

        PUBLIC
            FILE_SET HEADERS
            BASE_DIRS
                include
            FILES
                include/map.h
)

target_link_libraries(map
        PRIVATE
            MapLib
)

