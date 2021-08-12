#ifndef INC_05_HEAPIFY_QUICKSORT_H
#define INC_05_HEAPIFY_QUICKSORT_H

#include <iostream>
#include <ctime>
#include <algorithm>
#include "InsertionSort.h"

using namespace std;


// ��arr[l...r]���ֽ���partition����
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int _partition(T arr[], int l, int r) {

    // �����arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
    swap(arr[l], arr[rand() % (r - l + 1) + l]);

    T v = arr[l];
    int j = l;
    for (int i = l + 1; i <= r; i++)
        if (arr[i] < v) {
            j++;
            swap(arr[j], arr[i]);
        }

    swap(arr[l], arr[j]);

    return j;
}

// ��arr[l...r]���ֽ��п�������
template <typename T>
void _quickSort(T arr[], int l, int r) {

    // ����С��ģ����, ʹ�ò�����������Ż�
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = _partition(arr, l, r);
    _quickSort(arr, l, p - 1);
    _quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {

    srand(time(NULL));
    _quickSort(arr, 0, n - 1);
}

#endif //INC_05_HEAPIFY_QUICKSORT_H