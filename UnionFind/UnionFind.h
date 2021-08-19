// UnionFind.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

#include <cassert>

using namespace std;

namespace UF1 {
	class UnionFind {

	private:
		int count;
		int* id;

	public:
		UnionFind(int n) {
			this->count = n;
			id = new int[n];
			for (int i = 0; i < n;i++)
				id[i] = i;
		}

		~UnionFind() {
			delete id;
		}

		int find(int p) {
			assert(p >= 0 && p < this->count);
			return this->id[p];
		}

		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}

		void unionElements(int p, int q) {
			int pID = find(p);
			int qID = find(q);

			for (int i = 0; i < count;i++) {
				if (id[i] == pID) {
					id[i] = qID;
				}
			}
		}
	};
}

