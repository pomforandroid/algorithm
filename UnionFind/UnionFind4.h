#include <iostream>

// TODO: Reference additional headers your program requires here.

#include <cassert>

using namespace std;

namespace UF4 {
	class UnionFind {

	private:
		int count;
		int* parent;
		int* rank;

	public:
		UnionFind(int n) {
			this->count = n;
			parent = new int[n];
			rank = new int[n];
			for (int i = 0; i < n;i++) {
				parent[i] = i;
				rank[i] = 1;
			}
		}

		~UnionFind() {
			delete parent;
		}

		int find(int p) {
			assert(p >= 0 && p < this->count);
			while (p != parent[p]) {
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
			return p;
		}

		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}

		void unionElements(int p, int q) {
			int rootPID = find(p);
			int rootQID = find(q);

			if (rootPID == rootQID)
				return;
			if (rank[rootPID] < rank[rootQID]) {
				parent[rootPID] = rootQID;
			}
			else if (rank[rootPID] > rank[rootQID]) {
				parent[rootQID] = rootPID;
			}
			else {
				parent[rootPID] = rootQID;
				rank[rootQID] += 1;
			}
		}
	};
}