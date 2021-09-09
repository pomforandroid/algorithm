#ifndef DIJLSTRA_H
#define DIJLSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

// Dijkstra to find the Shortest path

template<typename Graph, typename Weight>
class Dijkstra {

private:
	Graph& G; //the reference of graph
	int s;  // beginning node
	Weight* distTo; //distTo[i] save the length of shortest path from beginning node s to node i remarked.
	bool* marked; // remark array, whether the remarded node i is visited;
	vector<Edge<Weight>*>from;  //from[i] recording which edge arrive the node i in the Shortest path;
								// it can help to restore total Shortest path
public:
	Dijkstra(Graph& graph, int s) :G(graph) {

		assert(s >= 0 && s < G.V());
		this->s = s;
		distTo = new Weight[G.V()];
		marked = new bool[G.V()];
		for (int i = 0; i < G.V(); i++) {
			distTo[i] = Weight();
			marked[i] = false;
			from.push_back(NULL);
		}
		// Use the index heap to record the shortest distance currently found to reach each node
		IndexMinHeap<Weight> ipq(G.V());

		distTo[s] = Weight();
		from[s] = new Edge <Weight>(s, s, Weight());
		ipq.insert(s, distTo[s]);
		marked[s] = true;

		while (!ipq.isEmpty()) {
			int v = ipq.extractMinIndex();

			//distTo[V] is the shortest path form s to v
			marked[v] = true;
			// Update all neighboring nodes of v
			typename Graph::adjIterator adj(G, v);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
				int w = e->other(v);
				// if the shorstest path have not find out from s to w
				if (!marked[w]) {
					// if w node did not find out the shortest path
					// or is visited ,bu through current node to w 's distance is shorter, then go to update it
					if (from[w] == NULL || distTo[v] + e->wt() < distTo[w]) {
						distTo[w] = distTo[v] + e->wt();
						from[w] = e;
						if (ipq.contain(w))
							ipq.change(w, distTo[w]);
						else
							ipq.insert(w, distTo[w]);
					}
				}
			}
		}

	}

	~Dijkstra() {
		delete[] distTo;
		delete[] marked;
		delete from[0];
	}


	Weight shortestPathTo(int w) {
		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));
		return distTo[w];
	}

	bool hasPathTo(int w) {
		assert(w >= 0 && w < G.V());
		return marked[w];
	}


	// 寻找从s到w的最短路径, 将整个路径经过的边存放在vec中
	void shortestPath(int w, vector<Edge<Weight>>& vec) {

		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));

		// 通过from数组逆向查找到从s到w的路径, 存放到栈中
		stack<Edge<Weight>*> s;
		Edge<Weight>* e = from[w];
		while (e->v() != this->s) {
			s.push(e);
			e = from[e->v()];
		}
		s.push(e);

		// 从栈中依次取出元素, 获得顺序的从s到w的路径
		while (!s.empty()) {
			e = s.top();
			vec.push_back(*e);
			s.pop();
		}
	}

	// 打印出从s点到w点的路径
	void showPath(int w) {

		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));

		vector<Edge<Weight>> vec;
		shortestPath(w, vec);
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i].v() << " -> ";
			if (i == vec.size() - 1)
				cout << vec[i].w() << endl;
		}
	}
};


#endif // !DIJLSTRA_H;
