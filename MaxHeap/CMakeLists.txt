﻿# CMakeList.txt : CMake project for MaxHeap, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("MaxHeap")

# Add source to this project's executable.
add_executable (MaxHeap "MaxHeap.cpp" "MaxHeap.h" "Heap.h"       "InsertionSort.h" "MergeSort.h" "QuickSort.h" "QuickSort2Ways.h" "QuickSort3Ways.h" "SortTestHelper.h"  "IndexMaxHeap.h")

# TODO: Add tests and install targets if needed.
