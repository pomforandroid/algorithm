# CMakeList.txt : CMake project for UnionFind, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("UnionFind")

# Add source to this project's executable.
add_executable (UnionFind "UnionFind.cpp" "UnionFind.h" "UnionFindTestHelper.h" "UnionFind2.h" "UnionFind3.h")

# TODO: Add tests and install targets if needed.
