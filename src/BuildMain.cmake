# Builds the main program, linking all the files and header files together

option(BUILD_MAIN "Build the main targets" ON)

if (BUILD_MAIN)

add_executable(task1 "${PROJECT_SOURCE_DIR}/task1.cpp")
target_link_libraries(
  task1 PRIVATE common_libraries
)
enable_warnings(task1 "PRIVATE")

add_executable(task2 "${PROJECT_SOURCE_DIR}/task2.cpp")
target_link_libraries(
  task2 PRIVATE common_libraries
)
enable_warnings(task2 "PRIVATE")

add_executable(benchmark "${PROJECT_SOURCE_DIR}/benchmark.cpp")
target_link_libraries(
  benchmark PRIVATE common_libraries
)
enable_warnings(benchmark "PRIVATE")

endif()
