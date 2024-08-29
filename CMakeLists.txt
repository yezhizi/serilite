cmake_minimum_required(VERSION 3.10)

project(serilite)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SeriLite_BUILD_EXAMPLES  CACHE BOOL "Build examples" ON) 

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(serilite INTERFACE)
target_include_directories(serilite INTERFACE ${CMAKE_SOURCE_DIR}/include)


if(SeriLite_BUILD_EXAMPLES)
    file(GLOB_RECURSE EXAMPLE_SOURCES ${CMAKE_SOURCE_DIR}/example/*.cpp)
    foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
        get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
        add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
        target_link_libraries(${EXAMPLE_NAME} serilite)
    endforeach()
endif()


