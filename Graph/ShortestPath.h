#include <iostream>
#include <cassert>
#include <stack>
#include <queue>
using namespace std;


template <typename Graph>
class ShortestPath {
private:
	int* from;
	bool* visited;
	int* ord;
	Graph& G;
	int s;

	void dfs(int v) {
		visited[v] = true;

		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next()) {
			if (!visited[i]) {
				from[i] = v;
				dfs(i);
			}
		}
	}
public:
	ShortestPath(Graph& graph, int s) :G(graph) {
		visited = new bool[G.V()];
		from = new int[G.V()];
		ord = new int[G.V()];
		for (int i = 0; i < G.V(); i++) {
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}
		this->s = s;
		
		// shortest path
		queue<int> q;
		q.push(s);
		ord[s] = 0;
		visited[s] = true;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			typename Graph::adjIterator adj(G, f);
			for (int i = adj.begin(); !adj.end(); i = adj.next()) {
				if (!visited[i]) {
					q.push(i);
					ord[i] = ord[f] + 1;
					visited[i] = true;
					from[i] = f;
				}
				
			}
			
		}
		
	}

	~ShortestPath() {
		delete[] visited;
		delete[] from;
		delete[] ord;
	}

	bool hasPath(int w) {
		assert(w >= 0 && w < G.V());
		return visited[w];
	}

	void path(int w, vector<int>& vec) {
		assert(w >= 0 && w < G.V());
		stack<int> s;

		int p = w;
		while (p != -1) {
			s.push(p);
			p = from[p];
		}

		vec.clear();
		while (!s.empty()) {
			vec.push_back(s.top());
			s.pop();
		}

	}

	void showPath(int w) {

		vector<int> vec;
		path(w, vec);
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if (i == vec.size() - 1)
				cout << endl;
			else
				cout << "->";

		}
	}

	int length(int w) {
		assert(w >= 0 && w < G.V());
		return ord[w];
	}
};