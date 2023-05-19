cmake_minimum_required(VERSION 3.14)
project(dummy)

include(FetchContent)
include(GoogleTest)

####################################################
# Set the C++ Standard to be used (Default to C++14)
####################################################
set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED ON)

####################################################
# Use gtest for testing
####################################################

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip
        GIT_SHALLOW    1
)
FetchContent_MakeAvailable(googletest)

enable_testing()

####################################################################
# Set Compiler flags
####################################################################
IF (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++${CXX_STANDARD}")
ELSEIF (MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
ENDIF()

####################################################################
# Add library: All header files are to be placed in dummy/inc/dummy,
# all source files are to be placed in dummy/src.
####################################################################
add_library(dummy_lib
  ${CMAKE_SOURCE_DIR}/
        dummy/src/FourWinsSetup.cpp dummy/inc/dummy/FourWinsSetup.hpp dummy/inc/dummy/BotPlayer.hpp dummy/src/BotPlayer.cpp)
target_include_directories(dummy_lib PUBLIC ${CMAKE_SOURCE_DIR}/dummy/inc)

####################################################################
# Add main executable.
####################################################################
add_executable(main
  ${CMAKE_SOURCE_DIR}/main/src/main.cpp
)
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/main/inc)
target_link_libraries(main dummy_lib)

####################################################################
# Add unit tests.
####################################################################
add_executable(dummy_test

  ${CMAKE_SOURCE_DIR}/dummy/test/UnitestBoard.cpp)
target_link_libraries(dummy_test GTest::gtest_main dummy_lib)
gtest_discover_tests(dummy_test)
