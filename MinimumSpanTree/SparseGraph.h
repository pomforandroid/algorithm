
#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"


using namespace std;

template <typename Weight>
class SparseGraph {

private:
	int n, m; //point, side
	bool directed;
	vector<vector<Edge<Weight>*>> g;

public:
	SparseGraph(int n, bool directed) {
		assert(n >= 0);
		this->n = n;
		this->m = 0;
		this->directed = directed;

		g = vector<vector< Edge<Weight>* >>(n, vector<Edge<Weight>*>());
	}

	~SparseGraph() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < g[i].size(); j++)
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
		
		g[w].push_back(new Edge<Weight>(w, v, weight));
		if (v != w && !directed)
			g[v].push_back(new Edge<Weight>(v, w, weight));
		m++;
	}

	bool hasEdge(int w, int v) {
		assert(w >= 0 && w < n);
		assert(v >= 0 && w < n);
		for (int i = 0; i < g[v].size(); i++)
			if (g[v][i]->other(v) == w)
				return true;
		return false;
	}

	void show() {
		for (int i = 0; i < n; i++) {
			cout << "vertex " << i << ":\t";
			for (int j = 0; j < g[i].size(); j++)
				cout << "( to:" << g[i][j]->w() << ",wt:" << g[i][j]->wt() << ")\t";
			cout << endl;
		}
	}

	class adjIterator {
	private:
		SparseGraph& G;
		int v;
		int index;

	public:
		adjIterator(SparseGraph& graph, int v) :G(graph) {
			this->v = v;
			this->index = 0;
		}
		~adjIterator() {}

		Edge<Weight>* begin() {
			index = 0;
			if (G.g[v].size()) {
				return G.g[v][index];
			}
			return NULL;
		}

		Edge<Weight>* next() {
			index++;
			if (index < G.g[v].size()) {
				return G.g[v][index];
			}
			return NULL;
		}

		bool end() {
			return index >= G.g[v].size();
		}

	};

};