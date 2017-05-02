# - Top level CMakeLists.txt for datatools ex_properties example program

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(BSTCUD LANGUAGES CXX)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(STATUS "${PROJECT_NAME} requires an out-of-source build.")
  message(STATUS "Please remove these files from ${CMAKE_BINARY_DIR} first:")
  message(STATUS "  CMakeCache.txt")
  message(STATUS "  CMakeFiles")
  message(STATUS "Once these files are removed, create a separate directory")
  message(STATUS "and run CMake from there, pointing it to:")
  message(STATUS "  ${CMAKE_SOURCE_DIR}")
  message(FATAL_ERROR "in-source build detected")
endif()

add_definitions("--std=c++11")
option(BSTCUD_WITH_EOS "Support for eos portable binary archives" OFF)

# - Boost
set(Boost_NO_BOOST_CMAKE ON)
find_package(Boost 1.58 REQUIRED serialization)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/eos_portable_archive/5.1)
include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_BINARY_DIR}/XY)
include_directories(${PROJECT_BINARY_DIR}/Z)
include_directories(${PROJECT_BINARY_DIR}/Plugin)
enable_testing()
add_subdirectory(XY)
add_subdirectory(Z)
add_subdirectory(Plugin)

# end of CMakeLists.txt
