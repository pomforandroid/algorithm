#include <iostream>

// TODO: Reference additional headers your program requires here.

#include <cassert>

using namespace std;

namespace UF2 {
	class UnionFind {

	private:
		int count;
		int* parent;

	public:
		UnionFind(int n) {
			this->count = n;
			parent = new int[n];
			for (int i = 0; i < n;i++)
				parent[i] = i;
		}

		~UnionFind() {
			delete parent;
		}

		int find(int p) {
			assert(p >= 0 && p < this->count);
			while (p != parent[p]) {
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

			parent[rootPID] = rootQID;
		}
	};
}