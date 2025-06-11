cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME "AbstractForest")
set(EXECUTABLE_NAME "test")

project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp) 
add_library(abstract_forest STATIC ${SOURCES})

add_executable(${EXECUTABLE_NAME} ${CMAKE_SOURCE_DIR}/test.cpp)

include_directories(${CMAKE_SOURCE_DIR}/)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE abstract_forest)

set(DEBUG_FLAGS -g -O0 -Wall -Wextra -Wpedantic -Wfatal-errors -fsanitize=address -fsanitize=undefined -DDEBUG_MODE)
set(RELEASE_FLAGS -Wfatal-errors -O3 -march=native -flto -DNDEBUG)

target_compile_options(${EXECUTABLE_NAME} PRIVATE
    $<$<CONFIG:DEBUG>:${DEBUG_FLAGS}>
    $<$<CONFIG:RELEASE>:${RELEASE_FLAGS}>
)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/bin/test ${CMAKE_SOURCE_DIR}/bin
)

