#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    cout << "The Sorted Array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int arr[], int low, int high)
{
    // 12, 2i, 13, 29, 0, 32, 3j
    int pivot = arr[low]; // pivot--->epicentre
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int arr[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        quicksort(arr, low, partitionindex - 1);  // for left sub-array
        quicksort(arr, partitionindex + 1, high); // for right sub-array
    }
}
int main()
{
    int arr[] = {0, 12, 2, 13, 29, 0, 32, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = size - 1;
    cout << "Array Before Sorting" << endl;
    display(arr, size);

    cout << "Array After Sorting" << endl;
    quicksort(arr, low, high);
    display(arr, size);
}