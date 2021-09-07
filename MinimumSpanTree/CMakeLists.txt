# CMakeList.txt : CMake project for MinimumSpanTree, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("MinimumSpanTree")

# Add source to this project's executable.
add_executable (MinimumSpanTree "MinimumSpanTree.cpp" "MinimumSpanTree.h" "DenseGraph.h" "ReadGraph.h" "SparseGraph.h" "Edge.h" "MinHeap.h" "LazyPrimMST.h" "IndexMinHeap.h" "PrimMST.h" "UF.h" "KruskalMST.h")

# TODO: Add tests and install targets if needed.
