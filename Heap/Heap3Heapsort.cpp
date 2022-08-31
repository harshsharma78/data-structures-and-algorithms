#include <bits/stdc++.h>
using namespace std;
void MaxHeapify(int arr[], int n, int idx)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest = idx;
    if (left < n && arr[left] > arr[idx])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != idx)
    {
        swap(arr[idx], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}
void MinHeapify(int arr[], int n, int idx)
{
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;
    if (left < n && arr[left] < arr[idx])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != idx)
    {
        swap(arr[idx], arr[smallest]);
        MinHeapify(arr, n, smallest);
    }
}
void MaxHeapsort(int arr[], int n) // Ascending Order
{
    for (int i = n / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0);
    }
}
void MinHeapsort(int arr[], int n) // Descending Order
{
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        MinHeapify(arr, i, 0);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Heap-array Before applying Heapsort" << endl;
    printarray(arr, size);

    cout << "Heap-array After applying Heapsort [Ascending Order]" << endl;
    MaxHeapsort(arr, size);
    printarray(arr, size);

    cout << "Heap-array After applying Heapsort [Descending Order]" << endl;
    MinHeapsort(arr, size);
    printarray(arr, size);
}