# Builds items which are commonly used between the main program and the tests.
# Usually these are classes, files and options which are used by the main program but
# are also tested individually

# Any common options are put as an interface
# rather than putting it with each file individually

include_directories("${PROJECT_SOURCE_DIR}")

add_compile_options(
  "$<$<CONFIG:Debug>:--coverage>" # only in debug mode
)
add_compile_options(
  "$<$<CONFIG:Release>:-O3>" # only in release mode
)
link_libraries(gcov)

include(FetchContent)

FetchContent_Declare(
  json
  GIT_REPOSITORY  https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_PROGRESS    TRUE
  GIT_SHALLOW     TRUE
  GIT_TAG         v3.11.2
)
FetchContent_MakeAvailable(json)


add_library(
  users
  "${PROJECT_SOURCE_DIR}/User/User.cpp"
)

# target_link_libraries(foo PRIVATE nlohmann_json::nlohmann_json)

# TODO: Add more cpu libraries here

# Combine Libaries
add_library(common_libraries INTERFACE)
target_link_libraries(
  common_libraries
  INTERFACE

  users
  # TODO: Combine more libraries that you create
)
