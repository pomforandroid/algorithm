
#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

template <typename Weight>
class DenseGraph {

private:
	int n, m;
	bool directed;
	vector<vector<Edge<Weight> *>> g; // save the pointer 

public:
	DenseGraph(int n, bool directed) {
		assert(n >= 0);
		this->n = n;
		this->m = 0;
		this->directed = directed;
		
		g = vector<vector<Edge<Weight>*>>(n, vector<Edge<Weight>*>(n, NULL));
	}

	~DenseGraph() {
		for (int i = 0; i < n;i++)
			for (int j = 0; j < n;j++)
				if (g[i][j] != NULL)
					delete g[i][j];
	}


	int V() {
		return n;
	}

	int E() {
		return m;
	}

	void addEdge(int w, int v, Weight weight) {
		
		assert(w >= 0 && w < n);
		assert(v >= 0 && w < n);
		if (hasEdge(w, v)) {
			delete g[w][v];
			if (v != w && !directed)
				delete g[v][w];
			m--;
		}
			
		g[w][v] = new Edge<Weight>(w, v, weight);
		if (v != w && !directed)
			g[v][w] = new Edge<Weight>(w, v, weight);
		m++;
	}

	bool hasEdge(int w, int v) {
		assert(w >= 0 && w < n);
		assert(v >= 0 && w < n);
		return g[w][v] != NULL;
	}

	// show the information of graph
	void show() {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (g[i][j])
					cout << g[i][j]->wt() << "\t";
				else
					cout << "NULL\t";
			cout << endl;
		}
	}

	class adjIterator {

	private:
		DenseGraph& G;
		int index;
		int v;
		

	public:
		adjIterator(DenseGraph &graph, int v):G(graph) {
			this->v = v;
			this->index = -1;
		}

		Edge<Weight>* begin() {
			index = -1;
			return next();
		}

		Edge<Weight>* next() {
			for (index += 1; index < G.V(); index++)
				if (G.g[v][index])
					return G.g[v][index];
			return NULL;
		}

		bool end() {
			return index >= G.V();
		}

	};
	

};