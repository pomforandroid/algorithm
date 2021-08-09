# CMakeList.txt : CMake project for QuickSort, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("QuickSort")

# Add source to this project's executable.
add_executable (QuickSort "QuickSort.cpp" "QuickSort.h" "SortTestHelper.h" "MergeSort.h" "InsertionSort.h")

# TODO: Add tests and install targets if needed.
