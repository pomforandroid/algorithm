# CMakeList.txt : CMake project for Graph, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Graph")

# Add source to this project's executable.
add_executable (Graph "Graph.cpp" "Graph.h" "DenseGraph.h" "SparseGraph.h" "ReadGraph.h")

# TODO: Add tests and install targets if needed.
