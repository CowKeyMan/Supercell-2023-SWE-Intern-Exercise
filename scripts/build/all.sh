#!/bin/sh
# Build the main executable, tests as well as documentation in debug mode

./scripts/build/compilation_commands.sh

mkdir -p build
cd build
# Run the cmake / static analysis checks
cmake \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=OFF \
  -DCMAKE_BUILD_TYPE=Debug \
  -DENABLE_CLANG_TIDY=ON \
  -DENABLE_HEADER_GUARDS_CHECK=ON \
  -DENABLE_CLANG_FORMAT_CHECK=ON \
  -DBUILD_MAIN=OFF \
  -DBUILD_TEST=OFF \
  -DBUILD_DOCS=OFF \
  -DENABLE_PROFILING=OFF \
  ..
cd ..


# the 'a' at the end is to reconfigure the cmake file
# ./scripts/build/debug.sh a
./scripts/build/release.sh a
./scripts/build/docs.sh a
./scripts/build/tests.sh a
