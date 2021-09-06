#ifndef _EDGE_H_
#define _EDGE_H_

#include <iostream>
#include <cassert>


using namespace std;

template <typename Weight>
class Edge {

private:
	int a, b; //there are tow point of Edge and the direction is a point to b
	Weight weight;
public:
	Edge(int a, int b, Weight weight) {
		this->a = a;
		this->b = b;
		this->weight = weight;
	}

	// empty construct and all member var will be default value
	Edge() {

	}

	~Edge() {

	}

	int v() {
		return a; // return the first point
	}

	int w() {
		return b;
	}


	Weight wt() {
		return weight; //return value weight;
	}

	//given a vertex, return another one
	int other(int w) {
		assert(w == a || w == b);
		return w == a ? b : a;
	}

	// output the information of edge
	friend ostream& operator<<(ostream& os, const Edge& e) {
		os << e.a << "-" << e.b << ": " << e.weight;
		return os;
	}

	// the comparation between edge 's sides, actually is the weight 's compartion
	bool operator<(Edge<Weight>& e) {
		return weight < e.wt();
	}
	bool operator<=(Edge<Weight>& e) {
		return weight <= e.wt();
	}
	bool operator>(Edge<Weight>& e) {
		return weight > e.wt();
	}
	bool operator>=(Edge<Weight>& e) {
		return weight >= e.wt();
	}
	bool operator==(Edge<Weight>& e) {
		return weight == e.wt();
	}

};

#endif // _EDGE_H_