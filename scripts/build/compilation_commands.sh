#!/bin/bash
# Generate the compilation commands

mkdir -p build
cd build
cmake \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
  -DCMAKE_BUILD_TYPE=Debug \
  -DENABLE_CLANG_TIDY=OFF \
  -DENABLE_HEADER_GUARDS_CHECK=OFF \
  -DENABLE_CLANG_FORMAT_CHECK=OFF \
  -DBUILD_MAIN=ON \
  -DBUILD_TEST=ON \
  -DBUILD_DOCS=OFF \
  -DENABLE_PROFILING=ON \
  ..
cd ..
