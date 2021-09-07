// MinimumSpanTree.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <iomanip>
#include "MinimumSpanTree.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "SparseGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "Edge.h"
#include <vector>
#include "KruskalMST.h"

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
    string filename = "D:\\wupengcong\\c++\\algorithm\\MinimumSpanTree\\testG1.txt";
    int V = 8;

    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

    // Test Lazy Prim MST
    cout << "Test Lazy Prim MST:" << endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for (int i = 0; i < mst.size(); i++)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << lazyPrimMST.result() << endl;

    cout << endl;


    // Test Prim MST
    cout << "Test Prim MST:" << endl;
    PrimMST<SparseGraph<double>, double> primMST(g);
    mst = primMST.mstEdges();
    for (int i = 0; i < mst.size(); i++)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << primMST.result() << endl;

    cout << endl;


    // Test Kruskal MST
    cout << "Test Kruskal MST:" << endl;
    KruskalMST<SparseGraph<double>, double> kruskalMST(g);
    mst = kruskalMST.mstEdges();
    for (int i = 0; i < mst.size(); i++)
        cout << mst[i] << endl;
    cout << "The MST weight is: " << kruskalMST.result() << endl;


  
    return 0;
}
