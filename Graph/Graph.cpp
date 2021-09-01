// Graph.cpp : Defines the entry point for the application.
//

#include "Graph.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"

using namespace std;


void baseTest() {
	int N = 20;
	int M = 100;
	srand(time(NULL));

	// Sparese Graph
	SparseGraph g1(N, false);
	for (int i = 0; i < M; i++) {
		int a = rand() % N;
		int b = rand() % N;
		g1.addEdge(a, b);
	}

	for (int v = 0; v < N; v++) {
		cout << v << " : ";
		SparseGraph::adjIterator adj(g1, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
			cout << w << " ";
		cout << endl;
	}
	cout << endl;


	// Dense Graph
	DenseGraph g2(N, false);
	for (int i = 0; i < M; i++) {
		int a = rand() % N;
		int b = rand() % N;
		g2.addEdge(a, b);
	}

	for (int v = 0; v < N; v++) {
		cout << v << " : ";
		DenseGraph::adjIterator adj2(g2, v);
		for (int w = adj2.begin(); !adj2.end(); w = adj2.next())
			cout << w << " ";
		cout << endl;
	}
	cout << endl;
}

void testReadGrap() {
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
}

void testComponent() {
	// TestG1.txt - g1 and g2
	string filename1 = "D://wupengcong//c++//algorithm//Graph//testG1.txt";
	SparseGraph g1 = SparseGraph(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename1);
	Component<SparseGraph> component1(g1);
	cout << "TestG1.txt, Using Sparse Graph, Component Count: " << component1.count() << endl;

	DenseGraph g2 = DenseGraph(13, false);
	ReadGraph<DenseGraph> readGraph2(g2, filename1);
	Component<DenseGraph> component2(g2);
	cout << "TestG1.txt, Using Dense Graph, Component Count: " << component2.count() << endl;

	cout << endl;

	// TestG2.txt - g3 and g4
	string filename2 = "D://wupengcong//c++//algorithm//Graph//testG2.txt";
	SparseGraph g3 = SparseGraph(6, false);
	ReadGraph<SparseGraph> readGraph3(g3, filename2);
	Component<SparseGraph> component3(g3);
	cout << "TestG2.txt, Using Sparse Graph, Component Count: " << component3.count() << endl;

	DenseGraph g4 = DenseGraph(6, false);
	ReadGraph<DenseGraph> readGraph4(g4, filename2);
	Component<DenseGraph> component4(g4);
	cout << "TestG2.txt, Using Dense Graph, Component Count: " << component4.count() << endl;
}

void testFindPath() {
	string filename = "D://wupengcong//c++//algorithm//Graph//testG2.txt";
	SparseGraph  g = SparseGraph(6, false);
	ReadGraph<SparseGraph> readGraph(g, filename);
	g.show();
	cout << endl;

	Path<SparseGraph> dfs(g, 0);
	cout << "DFS : ";
	dfs.showPath(5);
}


void testShortestPath() {
	string filename = "D://wupengcong//c++//algorithm//Graph//testG2.txt";
	SparseGraph  g = SparseGraph(6, false);
	ReadGraph<SparseGraph> readGraph(g, filename);
	g.show();
	cout << endl;

	ShortestPath<SparseGraph> bfs(g, 0);
	cout << "bfs : ";
	bfs.showPath(3);
}

int main()
{
	
	testShortestPath();

	return 0;

}
