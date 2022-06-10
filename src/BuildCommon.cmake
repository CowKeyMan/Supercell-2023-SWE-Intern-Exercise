# Builds items which are commonly used between the main program and the tests.
# Usually these are classes, files and options which are used by the main program but
# are also tested individually

# Any common options are put as an interface
# rather than putting it with each file individually

add_compile_options(
  "$<$<CONFIG:Debug>:--coverage>" # only in debug mode
)
add_compile_options(
  "$<$<CONFIG:Release>:-O3>" # only in release mode
)
link_libraries(gcov)

add_library(
  functions
  "${PROJECT_SOURCE_DIR}/Functions/Functions.cpp"
)
target_include_directories(
  functions PUBLIC "${PROJECT_SOURCE_DIR}/Functions"
)
enable_warnings(functions "PRIVATE")

# TODO: Add more cpu libraries here

# Combine Libaries
add_library(common_libraries INTERFACE)
target_link_libraries(
  common_libraries
  INTERFACE

  functions
  # TODO: Combine more libraries that you create
)
