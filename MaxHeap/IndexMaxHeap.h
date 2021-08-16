#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "MaxHeap.h"

using namespace std;

template <typename Item>
class IndexMaxHeap {

private:
    Item* data;
    int* indexes; // add an index array to maintain data
    int* reverse; //store the index i 's position in indexes
    int count;
    int capicatity;
    void shiftUp(int k) {
        while (k > 1 && data[indexes[k] / 2] < data[indexes[k]]) {
            swap(indexes[k / 2], indexes[k]);
            reverse[indexes[k / 2]] = k / 2;
            reverse[indexes[k]] = k;
            k = k / 2;
        }
    }

    void shiftDown(int k) {
        while (k * 2 <= count) // k*2 is k's left child ,if k * 2 >= count ,it means that k have no left child
        {
            int j = k * 2;
            if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
                j += 1;

            if (data[indexes[k]] > data[indexes[j]])
                break;

            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j; // update the k 
        }
    }

public:

    IndexMaxHeap(int capicatity) {
        data = new Item[capicatity + 1];
        indexes = new int[capicatity + 1];
        reverse = new int[capicatity + 1];
        for (int i = 0; i <= capicatity; i++) {
            reverse[i] = 0; // if there is no data ,init 0
        }
        count = 0;
        this->capicatity = capicatity;

    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }
    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool contain(int i) {
        assert(i + 1 >= 1 && i + 1 <= capicatity);
        return reverse[i] > 0;
    }

    // The user uses the INSERT method to start with 0.
    void insert(int i, Item item) {
        assert(i + 1 >= 1 && i + 1 <= capicatity); // 
        assert(count + 1 <=capicatity);
        i += 1;
        data[i] = item;//index begin at the 1 due to the MaxHeap 
        indexes[count + 1] = i; // save data 's index i in array index
        reverse[i] = count + 1; 
        count++;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);
        Item item = data[indexes[1]];// why is index[1] ,because the index[1] storeage the max data 's index in array
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        indexes[count] = 0;
        count--;
        shiftDown(1);
        return item;
    }

    int extractMaxIndex() {
        assert(count > 0);
        int res = indexes[1] -1; // why is index[1] -1, due to begin at 1
        swap(indexes[1], indexes[count]);
        reverse[1] = 1;
        indexes[count] = 0;
        count--;
        shiftDown(1);
        return res;
    }

    Item getItem(int i) {
        return data[i + 1);
    }

    void change(int i, Item item) {
        i += 1;
        data[i] = item;
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }

};