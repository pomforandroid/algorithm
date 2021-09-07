#ifndef KRUSKALMST_H
#define KRUSKALMST_H


#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "UF.h"
#include "Edge.h"

using namespace std;

template <typename Graph, typename Weight>
class KruskalMST {


private:
	vector<Edge<Weight>> mst; // all Edges included in mini span tree 
	Weight mstWeight;

public:
	KruskalMST(Graph& graph) {

		// save all edge in a miniheap (pq).
		MinHeap<Edge<Weight>> pq(graph.E());
		
		for (int i = 0; i < graph.V(); i++) {
			typename Graph::adjIterator adj(graph, i);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
				if (e->v() > e->w())
					pq.insert(*e);
		}

		// create a union find ,to find the connection of visited node;
		UnionFind uf = UnionFind(graph.V());
		while (!pq.isEmpty())
		{
			Edge<Weight> e = pq.extractMin();
			if (uf.isConnected(e.v(), e.w()))
				continue;

			mst.push_back(e);
			uf.unionElements(e.v(), e.w());
		}

		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size();i++)
			mstWeight += mst[i].wt();
	}

	~KruskalMST() { }

	vector<Edge<Weight>> mstEdges() {
		return mst;
	};

	Weight result() {
		return mstWeight;
	};
};










#endif // !KRUSKALMST_H

