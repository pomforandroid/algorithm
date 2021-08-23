#include <iostream>

// TODO: Reference additional headers your program requires here.

#include <cassert>

using namespace std;

namespace UF3 {
	class UnionFind {

	private:
		int count;
		int* parent;
		int* size;

	public:
		UnionFind(int n) {
			this->count = n;
			parent = new int[n];
			size = new int[n];
			for (int i = 0; i < n;i++) {
				parent[i] = i;
				size[i] = 1;
			}
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
			if (size[rootPID] < size[rootQID]) {
				parent[rootPID] = rootQID;
				size[rootQID] += size[rootPID];
			}
			else {
				parent[rootQID] = rootPID;
				size[rootPID] += size[rootQID];
			}
		}
	};
}