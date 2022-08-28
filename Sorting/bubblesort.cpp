#include <iostream>
using namespace std;
void swap(int *fst, int *sec)
{
    int temp = *fst;
    *fst = *sec;
    *sec = temp;
}
// void bubblesort(int arr[], int n)
// {
//     for (int k = 1; k <= n - 1; k++)
//     {
//         int ptr = 0;
//         while (ptr < n - k)
//         {
//             if (arr[ptr] > arr[ptr + 1])
//             {
//                 swap(arr[ptr], arr[ptr + 1]);
//             }
//             ptr++;
//         }
//     }
// }
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // for passes [passes will be size-2]
    {
        for (int j = 0; j < n - i - 1; j++)
        // loop will be executed 6 times, 5 times, 4 times, 3 times, 2 times, 1 times, 0 times
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void display(int arr[], int n)
{
    cout << "The Sorted Array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {12, 2, 132, 29, 1, 32, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array Before Sorting" << endl;
    display(arr, size);
    
    cout << "Array After Sorting" << endl;
    bubblesort(arr, size);
    display(arr, size);
}