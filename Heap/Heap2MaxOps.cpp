#include <bits/stdc++.h>
using namespace std;
class heap
{
    int *arr;
    int capacity;
    int heapsize;

public:
    heap(int cap)
    {
        capacity = cap;
        heapsize = 0;
        arr = new int[capacity];
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int l)
    {
        return (2 * l + 1);
    }
    int right(int r)
    {
        return (2 * r + 2);
    }
    int getmax()
    {
        return arr[0];
    }

    int extractmax()
    {
        if (heapsize <= 0)
        {
            return INT_MAX;
        }
        if (heapsize == 1)
        {
            heapsize--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[heapsize - 1];
        heapsize--;
        MaxHeapify(0);
        return root;
    }

    int MaxHeapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heapsize && arr[left] > arr[i])
            largest = left;
        if (right < heapsize && arr[right] > arr[i])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            MaxHeapify(largest);
        }
    }

    void InsertKey(int key)
    {
        if (heapsize > capacity)
            cout << "Heap Overflow" << endl;

        heapsize++;
        int i = heapsize - 1;
        arr[i] = key;

        while (i != 0 && arr[parent(i)] < arr[i]) // for Max-Heapify
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void DeleteKey(int i)
    {
        int lastele = arr[heapsize - 1];
        arr[0] = lastele;
        heapsize--;
        MaxHeapify(0);
    }
    void IncreaseKey(int i, int value)
    {
        arr[i] = value;
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    
};
int main()
{
    heap h(20);
    h.InsertKey(12);
    h.InsertKey(1);
    h.InsertKey(6);
    h.InsertKey(11);
    h.InsertKey(22);
    h.InsertKey(55);

    h.DeleteKey(55);
    
    h.IncreaseKey(12, 34);
    cout << h.getmax();
}
    // void DecreaseKey(int i, int value)
    // {
    //     arr[i] = value;
    //     while (i != 0 && arr[parent(i)] > arr[i])
    //     {
    //         swap(arr[i], arr[parent(i)]);
    //         i = parent(i);
    //     }
    // }