#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include <stack>
#include <vector>
#include "Edge.h"

using namespace std;

// using BellmanFord to find out the shortest path
template <typename Graph, typename Weight>
class BellmanFord {

private:
	Graph& G; // the reference of graph
	int s; //beginning node
	Weight* distTo; // distTo[i] record the shortest path length form beginning node s to i
	vector<Edge<Weight>*> from; //from[i] records the shortest path, which side reaches point i

	bool hasNegativeCycle;// Whether there is a negative weight ring in the mark graph

	// Determine whether there is a negative weight ring in the graph
	bool detectNegativeCycle() {
		for (int i = 0; i < G.V(); i++) {
			typename Graph::adjIterator adj(G, i);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
				if (from[e->v()] && distTo[e->v()] + e->wt() < distTo[e->w()])
					return true;
		}

		return false;

	}

public:
	BellmanFord(Graph& graph, int s) :G(graph) {
		this->s = s;
		distTo = new Weight[G.V()];
		// all node s are not reachable when init, that is show by from array
		for (int i = 0; i < G.V(); i++)
			from.push_back(NULL);

		// sets distTo[s] = 0 ;and make from[s] not be NULL, it means that the init node s is reachable and its distance is 0
		distTo[s] = Weight();
		from[s] = new Edge<Weight>(s, s, Weight());

		// Perform V-1 cycles, each cycle finds the shortest distance that can be reached from the starting point to all other points, 
		// using at most pass steps

		for (int pass = 1; pass < G.V(); pass++) {
			// perform a relaxation operation on all edges in each loop
			// The way to traverse all edges is to traverse all vertices first, and then traverse all edges adjacent to all vertices

			for (int i = 0; i < G.V();i++) {
				typename Graph::adjIterator adj(G, i);
				for(Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next())
					//For each edge, first judge that e->v() is reachable
					// Later, if e->w() has not arrived before, obviously we can update distTo[e->w()]
					// Or although e->w() has arrived before, but through this e we can get a shorter distance, that is, we can perform a relaxation operation, we can also update distTo[e->w()]
					if (from[e->v()] && (!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()])) {
						distTo[e->w()] = distTo[e->v()] + e->wt();
						from[e->w()] = e;
					}
			}
		}
        hasNegativeCycle = detectNegativeCycle();
	}

    // ��������
    ~BellmanFord() {

        delete[] distTo;
        delete from[s];
    }

    // ����ͼ���Ƿ��и�Ȩ��
    bool negativeCycle() {
        return hasNegativeCycle;
    }

    // ���ش�s�㵽w������·������
    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        assert(hasPathTo(w));
        return distTo[w];
    }

    // �жϴ�s�㵽w���Ƿ���ͨ
    bool hasPathTo(int w) {
        assert(w >= 0 && w < G.V());
        return from[w] != NULL;
    }

    // Ѱ�Ҵ�s��w�����·��, ������·�������ıߴ����vec��
    void shortestPath(int w, vector<Edge<Weight>>& vec) {

        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        assert(hasPathTo(w));

        // ͨ��from����������ҵ���s��w��·��, ��ŵ�ջ��
        stack<Edge<Weight>*> s;
        Edge<Weight>* e = from[w];
        while (e->v() != this->s) {
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        // ��ջ������ȡ��Ԫ��, ���˳��Ĵ�s��w��·��
        while (!s.empty()) {
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }

    // ��ӡ����s�㵽w���·��
    void showPath(int w) {

        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
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



#endif // !BELLMAN_FORD_H
