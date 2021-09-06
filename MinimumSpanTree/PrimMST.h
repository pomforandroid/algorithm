#ifndef PRIM_MST_H
#define PRIM_MST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"


using namespace std;

template <typename Graph, typename Weight>
class PrimMST {
private:
	Graph& G; // the refence of graph
	IndexMinHeap<Weight> ipq; // Minimum index heap, algorithm auxiliary data structure
	vector<Edge<Weight>*> edgeTo; // the edge corresponding to the visited point
	bool* marked; // mark whether node i is visited during the running of the algorithm
	vector<Edge<Weight>> mst; // All edges included in the minimum spanning tree
	Weight mstWeight;// Minimum spanning tree weight

	void visit(int v) {

		assert(!marked[v]);
		marked[v] = true;

		typename Graph::adjIterator adj(G, v);
		for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
			int w = e->other(v);
			if (!marked[w]) {
				if (!edgeTo[w]) {
					edgeTo[w] = e;
					ipq.insert(w, e->wt());
				}
				else if (e->wt() < edgeTo[w]->wt()) {
					edgeTo[w] = e;
					ipq.change(w, e->wt());
				}
			}
		}

	}

public:
	PrimMST(Graph &graph):G(graph), ipq(IndexMinHeap<Weight>(graph.V())) {
		assert(graph.E() >= 1);

		marked = new bool[G.V()];
		for (int i = 0; i < G.V();i++) {
			marked[i] = false;
			edgeTo.push_back(NULL);
		}
		mst.clear();

		//Prim
		visit(0);
		while (!ipq.isEmpty()) {
			int v = ipq.extractMinIndex();
			assert(edgeTo[v]);
			mst.push_back(*edgeTo[v]);
			visit(v);
		}
	}

	~PrimMST() {
		delete[] marked;
	}

	vector<Edge<Weight>> mstEdges() {
		return mst;
	};

	Weight result() {
		return mstWeight;
	};
};




#endif // !PRIM_MST_H
