
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DenseGraph {

private:
	int n, m;
	bool directed;
	vector<vector<bool>> g;

public:
	DenseGraph(int n, bool directed) {
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++)
			g.push_back(vector<bool>(n, false));

	}

	~DenseGraph() {

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
		if (hasEdge(w, v))
			return;
		g[w][v] = true;
		if (!directed)
			g[v][w] = true;
		m++;
	}

	bool hasEdge(int w, int v) {
		assert(w >= 0 && w < n);
		assert(v >= 0 && w < n);
		return g[w][v];
	}

	// show the information of graph
	void show() {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << g[i][j] << "\t";
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

		int begin() {
			index = -1;
			return next();
		}

		int next() {
			for (index += 1; index < G.V(); index++)
				if (G.g[v][index])
					return index;
			return -1;
		}

		bool end() {
			return index >= G.V();
		}

	};
	

};