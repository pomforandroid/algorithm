//
// Created by 吴鹏聪 on 2021/4/21.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <cassert>
using namespace std;

namespace SortTestHelper{

    int *generateRandomNearArray(int n, int near){
        int * arr = new int[n];
        srand(time(NULL));
        for(int i=0; i<n; i++){
            arr[i] = i;
        }
        for(int i = 0; i< near; i++){
            int l = rand() % n ;
            int r = rand() % n ;
            swap(arr[l], arr[r]);
        }
        return arr;
    }

    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL<=rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for(int i=0; i<n; i++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    template <typename T>
    void printArray(T t[], int n){
        for(int i = 0; i<n; i++){
            cout << t[i] << " ";
        }
    }
    template <typename  T>
    bool isSorted(T t[], int n){
        for(int i=0; i<n-1; i++){
            if(t[i]>t[i+1])
                return false;
        }
        return true;
    }

    template <typename T>
    void testSort(string sortname, void(*sort)(T[], int), T t[] , int n){
        clock_t start_time = clock();
        sort(t, n);
        clock_t end_time = clock();
        assert(isSorted(t, n));
        cout << "sortname: " << sortname <<" : "<< double (end_time-start_time) /CLOCKS_PER_SEC << "s";
    }

    int* copyIntArray(int a[], int n){
        int *arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }


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

    template<typename T>
    void insertionSort(T arr[], int l, int r){
        for(int i=l; i <r; i++){
            T e = arr[i];
            int j ;//save the position element e
            for(j=i; j>0 && arr[j-1]>e; j--){
                arr[j] = arr[j-1];
            }
            arr[j] = e;
        }
    }
}

#endif //SELECTIONSORT_SORTTESTHELPER_H
