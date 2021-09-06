#ifndef LAZY_PRIM_MST_H
#define LAZY_PRIM_MST_H



#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "MinHeap.h"

using namespace std;

template<typename Graph, typename Weight>
class LazyPrimMST {

private:
	Graph& G; //the references of graph
	MinHeap<Edge<Weight>> pq; //Minimal heap, algorithm-assisted data structure
	bool* marked; // mark whether node i is visited during the running of the algorithm
	vector<Edge<Weight>> mst; // All edges included in the minimum spanning tree
	Weight mstWeight;// Minimum spanning tree weight
	void visit(int v) {

		assert(!marked[v]);
		marked[v] = true;

		typename Graph::adjIterator adj(G, v);
		for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
			if (!marked[e->other(v)])
				pq.insert(*e);
		}

	}

public:
	// construct. using prim algorithm
	LazyPrimMST(Graph& graph) :G(graph), pq(MinHeap<Edge<Weight>>(graph.E())) {
		marked = new bool[G.V()];
		for (int i = 0; i < G.V();i++)
			marked[i] = false;
		mst.clear();

		//lazy prim
		visit(0);
		while (!pq.isEmpty()) {
			Edge<Weight> e = pq.extractMin();
			if (marked[e.v()] == marked[e.w()])
				continue;
			mst.push_back(e);
			if (!marked[e.v()])
				visit(e.v());
			else
				visit(e.w());
		}

		//cal the minspan tree weight
		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size(); i++)
			mstWeight += mst[i].wt();

	}

	~LazyPrimMST() {
		delete[] marked;
	}

	vector<Edge<Weight>> mstEdges() {
		return mst;
	}

	Weight result() {
		return mstWeight;
	}

};


#endif // ! LAZY_PRIM_MST_H