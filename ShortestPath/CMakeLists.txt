# CMakeList.txt : CMake project for ShortestPath, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ShortestPath")

# Add source to this project's executable.
add_executable (ShortestPath "ShortestPath.cpp" "ShortestPath.h" "DenseGraph.h" "Edge.h" "IndexMinHeap.h" "ReadGraph.h" "SparseGraph.h" "Dijkstra.h" "BellmanFord.h")

# TODO: Add tests and install targets if needed.
