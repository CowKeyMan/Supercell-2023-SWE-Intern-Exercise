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
  GIT_TAG         v3.11.2
  GIT_SHALLOW     TRUE
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  fmt
  QUIET
  GIT_REPOSITORY       https://github.com/fmtlib/fmt.git
  GIT_TAG              9.1.0
  GIT_SHALLOW          TRUE
)
FetchContent_MakeAvailable(fmt)

add_library(
  io_utils
  "${PROJECT_SOURCE_DIR}/Utils/IOUtils.cpp"
)

add_library(
  user
  "${PROJECT_SOURCE_DIR}/User/User.cpp"
)
target_link_libraries(user PRIVATE nlohmann_json::nlohmann_json)
add_library(
  user_map
  "${PROJECT_SOURCE_DIR}/User/UserMap.cpp"
)
target_link_libraries(user_map PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(io_utils PRIVATE fmt::fmt)
add_library(
  file_line_iterator
  "${PROJECT_SOURCE_DIR}/FileLineIterator/FileLineIterator.cpp"
)
target_link_libraries(file_line_iterator PRIVATE io_utils)
add_library(
  friends_task_handler
  "${PROJECT_SOURCE_DIR}/TaskHandler/FriendsTaskHandler.cpp"
)
target_link_libraries(friends_task_handler PRIVATE user_map nlohmann_json::nlohmann_json user)

# TODO: Add more cpu libraries here

# Combine Libaries
add_library(common_libraries INTERFACE)
target_link_libraries(
  common_libraries
  INTERFACE

  io_utils
  user
  user_map
  file_line_iterator
  friends_task_handler

  fmt::fmt
  nlohmann_json::nlohmann_json
  # TODO: Combine more libraries that you create
)
