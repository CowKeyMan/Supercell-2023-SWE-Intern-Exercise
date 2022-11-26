# This is the root cmake file where the sources lie
# Different CMake versions have more features.

cmake_minimum_required(VERSION 3.19)

project(
  CPP_github_workflow
  VERSION 1.0
  DESCRIPTION "A workflow base for any C++ project"
  HOMEPAGE_URL https://github.com/CowKeyMan/CPP_github_workflow
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

include(cmake/ExportCompileCommands.cmake)
include(cmake/PreventBuildingInCmakeDirectory.cmake)
include(cmake/StaticAnalyzers.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/Profiling.cmake)
include(cmake/Options.cmake)
include(cmake/CCache.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
add_subdirectory (documentation)
