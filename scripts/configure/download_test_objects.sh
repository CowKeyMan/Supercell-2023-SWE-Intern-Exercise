#!/bin/sh

cd test_objects
echo "Downloading tests"
wget -nc "https://supr.cl/swe-2023-tests" -O "tests.zip"
echo "Extracting tests"
unzip tests.zip
mv tests/* .
rm -r tests
rm tests.zip
cd ..
