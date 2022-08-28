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
void merge(int arr[], int low, int mid, int high)
{

    int n = (high - low) + 1;
    int *Arr = new int(n);

    int i = low, j = mid, k = low;

    while (i <= mid-1 && j <= high)
    {
        if (arr[i] <=arr[j])
        {
            Arr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            Arr[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid-1)
    {
        Arr[k] = arr[i]; // this loop for the rest of the elements
       // Arr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        Arr[k] = arr[j]; // this loop for the rest of the elements
        j++;
        k++;
    }
    for (i = low; i <= high; i++) // for copying the elements back to original array
    {
        arr[i] = Arr[i];
    }
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    mergesort(arr, low, high);
    display(arr, size);
}