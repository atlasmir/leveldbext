cmake_minimum_required(VERSION 3.17)
project(leveldbext)

set(CMAKE_CXX_STANDARD 17)

add_library(leveldbext)

# TODO: sanitize the linker path
link_directories(${CMAKE_PREFIX_PATH}/lib)
include_directories(${CMAKE_PREFIX_PATH}/include)

set(DB_PUBLIC_INCLUDE_DIR "include")


target_include_directories(leveldbext
  PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

target_sources(leveldbext
  PRIVATE
  "db_connector/leveldb_connector.cc"
  "spatial/trajdb_impl.cc"
  "util/encoding.h"
  PUBLIC
  "${DB_PUBLIC_INCLUDE_DIR}/db_connector/connector.h"
  "${DB_PUBLIC_INCLUDE_DIR}/spatial/trajdb.h"
  )

# This project uses GoogleTest
# https://github.com/google/googletest
find_package(GTest REQUIRED)
if (GTest_FOUND)
# Build tests
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  enable_testing()
  include(GoogleTest)
  function(leveldbext_test filename)
    get_filename_component(test_name ${filename} NAME_WE)
    add_executable(${test_name} ${filename})
    target_link_libraries(${test_name} GTest::gtest_main leveldbext)
    target_link_libraries(${test_name} leveldb)
    gtest_discover_tests(${test_name})
  endfunction()

  leveldbext_test("db_connector/leveldb_connector_test.cc")
  leveldbext_test("spatial/trajdb_test.cc")
endif ()