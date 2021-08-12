// MaxHeap.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Heap.h"



int main()
{
	cout << "Hello MaxHeap." << endl;
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	srand(time(NULL));
	for (int i = 0; i < 30;i++) {
		maxheap.insert(rand() % 100);
	}

    cout << "extract Max" << endl;
    while (!maxheap.isEmpty())
    {
        int max = maxheap.extractMax();
        cout << max << " -> " << endl;
    }

    maxheap.testPrint();

	cout << "MaxHeap.size: " <<maxheap.size() << endl;
	return 0;
}
