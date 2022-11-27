# Friends Network

This is my solution repository for the technical task for the supercell SWE intern position.

## Important Notes

* I have written my solution using C++
* My results have been tested on Ubuntu 20.04.
* In order to run the program, you will need to have OpenMP, a C++ compiler and CMake installed.
    * OpenMP can be installed using: `sudo apt install libomp-dev`.
    * The rest can be installed using `sudo apt install libomp-dev`.
* Compile everything using `./scripts/build/release`. This will generate three binaries:
    * `build/bin/task1`: This is the binary for task 1.
    * `build/bin/task2`: This is the binary for task 1.
    * `build/bin/benchmark`: This is a benchmark which will run the given file 5 times for as many threads that you have.
* To run the above executables, use `<binary_name> -i <input file>`.
* **Note for testing**: the values inside the json were assumed to not need to be ordrered. As a result, if strings are compared, they will not match, but if the outputs are converted to json, then they will match correctly.
* To run the tests, you need to first download the test objects by running `./scripts/configure/download_test_objects.sh`, then compile the tests using `./scripts/build/tests.sh` and then run them by using `./build/bin/test`.
* For more detailed documentation as well as reasons why I took certain decisions within the code base, please visit: <https://cowkeyman.github.io/Supercell-2023-SWE-Intern-Exercise/> and click on the documentation button. You will find further and cleaner instructions there.
