# Builds the testing program. We use googletest as a testing framework

option(BUILD_TEST "Build the main targets" ON)
if (BUILD_TEST)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(test_lib INTERFACE)
target_link_libraries(
  test_lib
  INTERFACE
  gtest
  gtest_main
  gmock
  gmock_main
  gcov
)

# Create cpu test executable
add_executable(
  test
  "${PROJECT_SOURCE_DIR}/test_main.cpp"

  "${PROJECT_SOURCE_DIR}/Utils/IOUtils_test.cpp"

  "${PROJECT_SOURCE_DIR}/User/User_test.cpp"
  "${PROJECT_SOURCE_DIR}/User/UserMap_test.cpp"
  "${PROJECT_SOURCE_DIR}/FileLineIterator/FileLineIterator_test.cpp"
  "${PROJECT_SOURCE_DIR}/FileLineIterator/ReadAllFileLineIterator_test.cpp"
  "${PROJECT_SOURCE_DIR}/TaskHandler/FriendsTaskHandler_test.cpp"
  # "${PROJECT_SOURCE_DIR}/TaskHandler/UpdateTaskHandler_test.cpp"
  "${PROJECT_SOURCE_DIR}/UserUpdateObserver/StdoutUserUpdateObserver_test.cpp"

  # TODO: add more tests sources here
)
add_test(NAME test COMMAND test)
target_link_libraries(
  test PRIVATE test_lib common_libraries
)

endif()
