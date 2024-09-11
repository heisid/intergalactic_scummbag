cmake_minimum_required(VERSION 3.30)
project(intergalactic_scummbag C)

set(CMAKE_C_STANDARD 11)

add_executable(intergalactic_scummbag main.c
        libs/cJSON.c
        router.c
        router.h
        request.c
        request.h
        frontend.c
        frontend.h
        constants.h)

find_package(CURL REQUIRED)
target_link_libraries(intergalactic_scummbag CURL::libcurl)
