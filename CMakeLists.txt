# CMakeList.txt : CMake project for isolatedBoxCmake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("isolatedBoxCmake")

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/*.cpp"
        "${PROJECT_SOURCE_DIR}/*.h"
        )


# Add source to this project's executable.
add_executable (isolatedBoxCmake  ${all_SRCS} "isolatedBox_actuator.cpp" "isolatedBox_PID.h" "isolatedBox_PID.cpp" "main.cpp")

# TODO: Add tests and install targets if needed.
