#ifndef INC_05_HEAPIFY_QUICKSORT3WAYS_H
#define INC_05_HEAPIFY_QUICKSORT3WAYS_H

#include <iostream>
#include <algorithm>
#include "InsertionSort.h"

using namespace std;

// �ݹ����·���������㷨
template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {

    // ����С��ģ����, ʹ�ò�����������Ż�
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    // �����arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
    swap(arr[l], arr[rand() % (r - l + 1) + l]);

    T v = arr[l];

    int lt = l;     // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l + 1;    // arr[lt+1...i) == v
    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[i], arr[lt + 1]);
            i++;
            lt++;
        }
        else if (arr[i] > v) {
            swap(arr[i], arr[gt - 1]);
            gt--;
        }
        else { // arr[i] == v
            i++;
        }
    }

    swap(arr[l], arr[lt]);

    __quickSort3Ways(arr, l, lt - 1);
    __quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n) {

    srand(time(NULL));
    __quickSort3Ways(arr, 0, n - 1);
}

#endif //INC_05_HEAPIFY_QUICKSORT3WAYS_H