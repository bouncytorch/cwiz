cmake_minimum_required(VERSION 3.10)
project(cwiz C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT (CMAKE_BUILD_TYPE OR DEFINED ENV{CMAKE_BUILD_TYPE}))
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Default build type")
endif()

add_library(cwiz STATIC src/cwiz.cpp)
target_include_directories(cwiz PUBLIC include/ ${CMAKE_SOURCE_DIR}/vendor/skia/include/)
target_link_libraries(cwiz m ${CMAKE_SOURCE_DIR}/vendor/skia/libskia.a)

add_executable(cwiz-cli cli/main.cpp)
target_link_libraries(cwiz-cli PRIVATE cwiz)
set_target_properties(cwiz-cli PROPERTIES
    OUTPUT_NAME        cwiz
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
