cmake_minimum_required(VERSION 3.8)
project(KIT_ProjectExII_CPU_Simulator)

set(CMAKE_C_STANDARD 99)

add_subdirectory(Operation)

set(SOURCE_FILES
        ${SOURCE_FILES}
        main.c
        cpuboard.c
        cpuboard.h)

add_executable(KIT_ProjectExII_CPU_Simulator ${SOURCE_FILES})
target_link_libraries(KIT_ProjectExII_CPU_Simulator operations)