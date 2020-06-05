cmake_minimum_required(VERSION 3.14)

project(flibc C)

option(FLIBC_BUILD_TESTS "Build tests and enable the test target" OFF)

add_subdirectory(src)

if(FLIBC_BUILD_TESTS)
  enable_testing()
  include(CTest)
  add_subdirectory(test)
endif()
