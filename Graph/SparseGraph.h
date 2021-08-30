#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class SparseGraph {

private:
	int n, m; //point, side
	bool directed;
	vector <vector<int>> g;

public:
	SparseGraph(int n, bool directed) {
		this->n = n;
		this->m = m;
		this->directed = directed;
		for (int i = 0;i < n;i++) {
			g.push_back(vector<int>());
		}
	}

	~SparseGraph() {

	}

	int V() {
		return n;
	}

	int E() {
		return m;
	}


	void addEdge(int w, int v) {

		assert(w >= 0 && w < n);
		assert(v >= 0 && w < n);
		
		g[w].push_back(v);
		if (v!=w && !directed)
			g[v].push_back(w);
		m++;
	}

	bool hasEdge(int w, int v) {
		assert(w >= 0 && w < n);
		assert(v >= 0 && w < n);
		for (int i = 0;i < g[w].size();i++) {
			if (g[w][i] == v)
				return true;
		}
		return false;
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

		int begin() {
			index = 0;
			if (G.g[v].size()) {
				return G.g[v][index];
			}
			return -1;
		}

		int next() {
			index++;
			if (index < G.g[v].size()) {
				return G.g[v][index];
			}
			return -1;
		}

		bool end() {
			return index >= G.g[v].size();
		}

	};

};