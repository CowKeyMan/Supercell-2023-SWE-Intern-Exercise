# Builds the main program, linking all the files and header files together

option(BUILD_MAIN "Build the main targets" ON)

if (BUILD_MAIN)

add_executable(main main.cpp)
target_link_libraries(
  main PRIVATE common_libraries
)
enable_warnings(main "PRIVATE")

endif()
