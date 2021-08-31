// Graph.cpp : Defines the entry point for the application.
//

#include "Graph.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

using namespace std;

int main()
{
	int N = 20;
	int M = 100;
	srand(time(NULL));

	//// Sparese Graph
	//SparseGraph g1(N, false);
	//for (int i = 0; i < M; i++) {
	//	int a = rand() % N;
	//	int b = rand() % N;
	//	g1.addEdge(a, b);
	//}

	//for (int v = 0; v < N; v++) {
	//	cout << v << " : ";
	//	SparseGraph::adjIterator adj(g1, v);
	//	for (int w = adj.begin(); !adj.end(); w = adj.next())
	//		cout << w << " ";
	//	cout << endl;
	//}
	//cout << endl;


	//// Dense Graph
	//DenseGraph g2(N, false);
	//for (int i = 0; i < M; i++) {
	//	int a = rand() % N;
	//	int b = rand() % N;
	//	g2.addEdge(a, b);
	//}

	//for (int v = 0; v < N; v++) {
	//	cout << v << " : ";
	//	DenseGraph::adjIterator adj2(g2, v);
	//	for (int w = adj2.begin(); !adj2.end(); w = adj2.next())
	//		cout << w << " ";
	//	cout << endl;
	//}
	//cout << endl;



	// 使用两种图的存储方式读取testG1.txt文件
	string filename = "D://wupengcong//c++//algorithm//Graph//testG1.txt";
	SparseGraph g1(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename);
	cout << "test G1 in Sparse Graph:" << endl;
	g1.show();

	cout << endl;

	DenseGraph g2(13, false);
	ReadGraph<DenseGraph> readGraph2(g2, filename);
	cout << "test G1 in Dense Graph:" << endl;
	g2.show();

	cout << endl;

	// 使用两种图的存储方式读取testG2.txt文件
	filename = "D://wupengcong//c++//algorithm//Graph//testG2.txt";
	SparseGraph g3(6, false);
	ReadGraph<SparseGraph> readGraph3(g3, filename);
	cout << "test G2 in Sparse Graph:" << endl;
	g3.show();

	cout << endl;

	DenseGraph g4(6, false);
	ReadGraph<DenseGraph> readGraph4(g4, filename);
	cout << "test G2 in Dense Graph:" << endl;
	g4.show();

	return 0;

}
