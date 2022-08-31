#include <bits/stdc++.h>
using namespace std;
// Heapify

// int root = (i - 1) / 2;
// int right = (2 * i) + 2;
// int left = (2 * i) + 1;

void MaxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int right = (2 * i) + 2;
    int left = (2 * i) + 1;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    else
        largest = i;
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}
void MinHeapify(int arr[], int n, int i)
{
    int smallest = i;
    int right = (2 * i) + 2;
    int left = (2 * i) + 1;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    else
        smallest = i;
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        MinHeapify(arr, n, smallest);
    }
}
void buildMaxHeap(int arr[], int n)
{
    int startidx = (n / 2) - 1;
    for (int i = startidx; i >= 0; i--)
    {
        MaxHeapify(arr, n, i);
    }
}
void buildMinHeap(int arr[], int n)
{
    int startidx = (n / 2) - 1; // Range or Levels in a Binary Heap
    for (int i = startidx; i >= 0; i--)
    {
        MinHeapify(arr, n, i);
    }
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {20, 12, 22, 81, 4, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Building Heap from it" << endl;
    printarray(arr, size);

    cout << "Building Max-Heap from an Array" << endl;
    buildMaxHeap(arr, size);
    printarray(arr, size);

    cout << "Building Min-Heap from an Array" << endl;
    buildMinHeap(arr, size);
    printarray(arr, size);
}