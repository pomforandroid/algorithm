// MinimumSpanTree.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <iomanip>
#include "MinimumSpanTree.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "SparseGraph.h"
#include "LazyPrimMST.h"
#include "Edge.h"
#include <vector>

using namespace std;

void basicTest() {
    string filename = "D:\\wupengcong\\c++\\algorithm\\MinimumSpanTree\\testG1.txt";
    int V = 8;
    cout << fixed << setprecision(2);

    // Test Weighted Dense Graph
    DenseGraph<double> g1 = DenseGraph<double>(V, false);
    ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);
    g1.show();
    cout << endl;

    // Test Weighted Sparse Graph
    SparseGraph<double> g2 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);
    g2.show();
    cout << endl;
}

void minTreeTest() {
    string filename = "D:\\wupengcong\\c++\\algorithm\\MinimumSpanTree\\testG1.txt";
    int V = 8;

    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

    cout << "Test lazy prim MST:" << endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for (int i = 0; i < mst.size();i++)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << lazyPrimMST.result() << endl;

    cout << endl;
}

int main()
{
    minTreeTest();

  
    return 0;
}
