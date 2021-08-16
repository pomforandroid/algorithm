// BinarySearch.cpp : Defines the entry point for the application.
//

#include "BinarySearch.h"

using namespace std;

// seach in arr[l...n-1]
//return the index of the targe which is finded in arr[]. it return -1 when search nothing
template<typename T>
int binarySearch(T arr[], int n, T targe) {
	int l = 0;
	int r = n - 1;
	while (l<=r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] = targe) {
			return mid;
		}
		else if (arr[mid] < targe) {
			r = mid - 1; //why not including mid, due to arr[mid]=targe is excluded
		}
		else {
			r = mid + 1; //why not including mid, due to arr[mid]=targe is excluded
		}
	}
	return -1;
}

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
