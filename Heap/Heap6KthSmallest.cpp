#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int *arr;
    int capacity;
    int heapsize;

public:
    MaxHeap(int a[], int n)
    {
        heapsize = n;
        arr = a;
        for (int i = (heapsize - 1) / 2; i >= 0; i--)
            MaxHeapify(i);
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
};
class MinHeap
{
    int *arr;
    int capacity;
    int heapsize;

public:
    MinHeap(int a[], int n)
    {
        heapsize = n;
        arr = a;
        for (int i = (heapsize - 1) / 2; i >= 0; i--)
            MinHeapify(i);
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
    int getmin()
    {
        return arr[0];
    }
    int extractmin()
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
        MinHeapify(0);
        return root;
    }
    int MinHeapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapsize && arr[left] < arr[i])
            smallest = left;
        if (right < heapsize && arr[right] < arr[i])
            smallest = right;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            MinHeapify(smallest);
        }
    }
};
int KthSmallestUsingMaxHeap(int a[], int n, int k) // O(K + (N - k) * logk)
{
    MaxHeap max(a, k);
    for (int i = k; i < n; i++)
    {
        if (a[i] < max.getmax())
        {
            a[0] = a[i];
            max.MaxHeapify(0);
        }
    }
    return max.getmax();
}
int KthSmallestUsingMinHeap(int a[], int n, int k) // O(N + Klogn)
{
    MinHeap min(a, n);
    for (int i = 0; i < k - 1; i++)
    {
        min.extractmin();
    }
    return min.getmin();
}
int KthSmallestUsingQuickSelect(int arr[], int low, int high, int k)
{
}
int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The Kth Smallest Element [Max-Heap]--> " << KthSmallestUsingMaxHeap(arr, n, 4) << endl;
    // cout << "The Kth Smallest Element [Min-Heap]--> " << KthSmallestUsingMinHeap(arr, n, 4) << endl;
    // cout << "The Kth Smallest Element [Quick Select]--> " << KthSmallestUsingQuickSelect(arr, 0, n - 1, 2) << endl;
}
