#include <iostream>
using namespace std;
// Starts from index 1
void display(int arr[], int n)
{
    cout << "The Sorted Array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertionsort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++) // Loop for passes
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key)) // loop for each pass or sub-passes
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {12, 2, 13, 29, 0, 32, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Sorting" << endl;
    display(arr, size);

    cout << "Array After Sorting" << endl;
    insertionsort(arr, size);
    display(arr, size);
}