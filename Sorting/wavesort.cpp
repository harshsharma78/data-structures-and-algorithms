#include <iostream>
using namespace std;
void swap(int *fst, int *sec)
{
    int temp = *fst;
    *fst = *sec;
    *sec = temp;
}
void display(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void wavesort(int arr[], int n)
{
    int i;
    for (i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(&arr[i], &arr[i - 1]);
        }
        if (arr[i] > arr[i + 1] && i < n - 1)
        {
            swap(&arr[i], &arr[i + 1]);
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array Before Sorting" << endl;
    display(arr, size);

    cout << "Array After Sorting" << endl;
    wavesort(arr, size);
    display(arr, size);
}
