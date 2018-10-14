cmake_minimum_required(VERSION 3.12)
project(OpenMPTest)

set(CMAKE_CXX_STANDARD 14)

message(STATUS "Checking OpenMP")

find_package(OpenMP)

IF(OPENMP_FOUND)
    message("Found OpenMP!")
    # add flags for OpenMP
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${OpenMP_SHARED_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
ELSE()
    message("Missed OpenMP!")
ENDIF()

#add_executable(OpenMPTest parallel_for.cpp sequence.cpp helpers.cpp helpers.h parallel_sections.cpp parallel_handle.cpp)
add_executable(OpenMPTest  sequence.cpp parallel_handle.cpp helpers.cpp helpers.h)