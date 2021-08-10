#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
using namespace std;

template<typename T>
void __merge(T arr[], int l, int mid, int r){
    T *aux = new T[r-l+1];
    for(int i=l; i<=r; i++){
        aux[i-l] = arr[i];
    }
    int i = l;
    int j = mid + 1;
    for(int k=l; k<=r; k++){
        if(i>mid){
            arr[k] = aux[j-l];
            j++;
        }else if(j>r){
            arr[k] = aux[i-l];
            i++;
        }else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }else{
            arr[k] = aux[j-l];
            j++;
        }
    }

}


//递归使用递归排序，对arr[l,r]的范围进行排序
template<typename T>
void __mergesort(T arr[], int l, int r){
    if(r-l > 1024){
        SortTestHelper::insertionSort(arr, l, r);
        return;
    }

    int mid = (l + r) /2;

    __mergesort(arr, l, mid);
    __mergesort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);

}

template<typename T>
void mergeSortBU(T arr[], int n){
    for(int sz=1; sz < n; sz+=sz)
        for(int i=0; i+sz < n; i+= sz+sz )
            __merge(arr, i, i+sz-1, min(i+sz+sz-1, n-1));
}

template<typename T>
void mergeSort(T arr[], int n){
    __mergesort(arr ,0, n-1);
}

int main() {
    int n = 50000;
    int* arr = SortTestHelper::generateRandomNearArray(n,10);
    int* arr2 =SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("MergeBU", mergeSortBU, arr2, n);
    SortTestHelper::testSort("merge", mergeSort, arr, n);
    delete arr;
    delete arr2;

    return 0;
}
