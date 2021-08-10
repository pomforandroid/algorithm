// MaxHeap.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "MaxHeap.h"

using namespace std;

template <typename Item>
class MaxHeap {

private:
	Item* data;
	int count;

public:
	MaxHeap(int capicatity) {
		data = new Item[capicatity + 1];
		count = 0;
	}

	~MaxHeap() {
		delete[] data;
	}
	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}
};

int main()
{
	cout << "Hello MaxHeap." << endl;
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout << "MaxHeap.size: " <<maxheap.size() << endl;
	return 0;
}
