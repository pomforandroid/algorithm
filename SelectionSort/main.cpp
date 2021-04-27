#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

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

template <typename  T>
void selectionSort(T arr[], int n){
    for( int i = 0 ; i < n ; i++ ){
        int minIndex = i;
        for( int j = i+1; j < n ; j++ ){
            if( arr[j] < arr[minIndex] )
               minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int n = 10000;
    int *arr = SortTestHelper::generateRandomNearArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
//    selectionSort(arr, n);
//    SortTestHelper::printArray(arr, n);

    SortTestHelper::testSort("selectSort", selectionSort, arr, n);
    SortTestHelper::testSort("insertionSort", insertionSort, arr2, n);

    delete arr;
    delete arr2;
    //float
    //string
    Student d[3] = {{"xiaoming", 100}, {"xiaohong", 59}, {"zhangsan", 60}};
    selectionSort(d, 3);
    for(int i=0; i<3; i++)
        cout << d[i] << " ";
    return 0;
}
