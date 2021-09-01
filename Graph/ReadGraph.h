#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

template <typename Graph>
class ReadGraph {

public:
	ReadGraph(Graph& graph, const string& filename) {
		ifstream file(filename);
		string line;
		int V, E;
		assert(file.is_open());
		// first line is reading the num of point and side in graph
		assert(getline(file, line));
		stringstream ss(line);
		ss >> V >> E;
		assert(V == graph.V());
		//read every side 's information
		for (int i = 0; i < E;i++) {
			assert(getline(file, line));
			stringstream ss(line);

			int a, b;
			ss >> a >> b;
			assert(a >= 0 && a < V);
			assert(b >= 0 && b < V);
			graph.addEdge(a, b);
		
		}
	}

};