# Builds the main program, linking all the files and header files together

option(BUILD_MAIN "Build the main targets" ON)

if (BUILD_MAIN)

add_executable(task1 "${PROJECT_SOURCE_DIR}/task1.cpp")
target_link_libraries(
  task1 PRIVATE common_libraries
)
enable_warnings(task1 "PRIVATE")

endif()
