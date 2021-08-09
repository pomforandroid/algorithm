// QuickSort.cpp : Defines the entry point for the application.
//

#include "QuickSort.h"
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;
// partition2 solve the probrem that if there are so many duplicate data
// partition this park which is arr[l...r]
// return p, make that arr[l...p-1] < arr[p]; arr[p+1...r]>arr[p]
template <typename T>
int __partition2(T arr[], int l, int r) {

	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	// arr[l+1...i] <v; arr[j...r) >v
	int i = l + 1;
	int j = r;
	while (true) {
		while (i <= r && arr[i] < v) i++;
		while (j >= l+1 && arr[j] > v) j--;
		if (i > j) break;	
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	swap(arr[l], arr[j]);
	return j;
	
}


// partition this park which is arr[l...r]
// return p, make that arr[l...p-1] < arr[p]; arr[p+1...r]>arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {

	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	// arr[l+1...j] <v; arr[j+1...i) >v
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < v) { //>v do nothing
			swap(arr[i], arr[j+1]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

// qucik sort this park which is arr[l...r]
template <typename T>
void __quickSort(T arr[], int l, int r) {
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	int p = __partition2(arr, l, r);
	__quickSort(arr, l, p-1);
	__quickSort(arr, p+1, r);

}

template <typename T>
void quickSort(T arr[], int n) {
	srand(time(NULL));
	__quickSort(arr, 0, n-1);
}

//make sure that arr[l+1,lt] < v; arr[lt+1,i) =v; arr[gt,r] >v 
template <typename T>
void __quickSort3Way(T arr[], int l, int r) {
	
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	//partition
	int lt = l;
	int i = lt + 1;
	int gt = r + 1;
	//it is very clever that i make arr[l+1,lt] arr[lt+1,i) arr[gt,r] both of them are empty at the first 
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt+1]);
			lt++;
			i++;
		}
		else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else {
			i++;
		}
	}
	swap(arr[l], arr[lt]);
	__quickSort3Way(arr, l, lt - 1);
	__quickSort3Way(arr, gt, r);
}


template <typename T>
void quickSort3way(T arr[], int n) {
	srand(time(NULL));
	__quickSort3Way(arr, 0, n-1);
}

int main()
{
	cout << "Hello CMake." << endl;

	int n = 1000000;
	int swapTimes = 100;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);
	SortTestHelper::testSort("QUICK SORT", quickSort, arr1, n);
	SortTestHelper::testSort("MERGE SORT", mergeSort, arr2, n);
	SortTestHelper::testSort("QUICK SORT 3 way", quickSort3way, arr3, n);
	
	
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	return 0;
}
