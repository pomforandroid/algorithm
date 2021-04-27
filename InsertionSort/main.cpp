#include <iostream>
#include "SortTestHelper.h"

template<typename T>
void insertionSort(T arr[], int n){
    for(int i=1; i <n; i++){
        T e = arr[i];
        int j ;//save the position element e
        for(j=i; j>0 && arr[j-1]>e; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    int n = 1000;
    int *arr = SortTestHelper::generateRandomNearArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("selectionSort", SortTestHelper::selectionSort, arr, n);
    SortTestHelper::testSort("insertionSort", insertionSort, arr2, n);

    return 0;
}
