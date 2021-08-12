#ifndef INC_05_HEAPIFY_MERGESORT_H
#define INC_05_HEAPIFY_MERGESORT_H

#include <iostream>
#include <algorithm>
#include "InsertionSort.h"

using namespace std;


// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
// ����auxΪ���merge��������Ҫ�ĸ����ռ�
template<typename  T>
void __merge(T arr[], T aux[], int l, int mid, int r) {

    // ����aux�Ĵ�С��arrһ��, ��������Ҳ����Ҫ����aux������ƫ����
    // ��һ����ʡ�˼�����:)
    for (int i = l; i <= r; i++)
        aux[i] = arr[i];

    // ��ʼ����iָ����벿�ֵ���ʼ����λ��l��jָ���Ұ벿����ʼ����λ��mid+1
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {

        if (i > mid) {  // �����벿��Ԫ���Ѿ�ȫ���������
            arr[k] = aux[j]; j++;
        }
        else if (j > r) {  // ����Ұ벿��Ԫ���Ѿ�ȫ���������
            arr[k] = aux[i]; i++;
        }
        else if (aux[i] < aux[j]) {  // ��벿����ָԪ�� < �Ұ벿����ָԪ��
            arr[k] = aux[i]; i++;
        }
        else {  // ��벿����ָԪ�� >= �Ұ벿����ָԪ��
            arr[k] = aux[j]; j++;
        }
    }

}

// ʹ���Ż��Ĺ鲢�����㷨, ��arr[l...r]�ķ�Χ��������
// ����auxΪ���merge��������Ҫ�ĸ����ռ�
template<typename T>
void __mergeSort(T arr[], T aux[], int l, int r) {

    // ����С��ģ����, ʹ�ò�������
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l + r) / 2;
    __mergeSort(arr, aux, l, mid);
    __mergeSort(arr, aux, mid + 1, r);

    // ����arr[mid] <= arr[mid+1]�����,������merge
    // ���ڽ������������ǳ���Ч,���Ƕ���һ�����,��һ����������ʧ
    if (arr[mid] > arr[mid + 1])
        __merge(arr, aux, l, mid, r);
}


template<typename T>
void mergeSort(T arr[], int n) {

    // �� mergeSort��, ����һ��������aux�ռ�,
    // ������������ռ��Բ�����ʽ���ݸ���ɹ鲢����ĸ����Ӻ���
    T* aux = new T[n];

    __mergeSort(arr, aux, 0, n - 1);

    delete[] aux;   // ʹ��C++, new�����Ŀռ䲻Ҫ�����ͷŵ�:)
}

#endif //INC_05_HEAPIFY_MERGESORT_H