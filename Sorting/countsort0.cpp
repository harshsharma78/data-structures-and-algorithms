#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countsort(int arr[], int n)
{
    int range = 29;
    int aux[n];
    int i;
    int count[range + 1] = {};
    // memset(count, 0, sizeof(count));
    for (i = 0; i < n; ++i)
    {
        ++count[arr[i]]; // counting the number of elements of arr[] ----> how many times an element occur
    }
    for (i = 1; i <= range; ++i)
    {
        count[i] += count[i - 1]; // for finding how many positions a number has occupied
    }
    // for (i = 0; i < n; i++)
    // {
    //     aux[count[arr[i]]] = arr[i]; // adding the elements in a temp array to sort the elements
    //     --count[arr[i]];             // decresing the index of count by 1 and then adding the value at correct position --->(mandatory)
    // }

    for (i = n - 1; i >= 0; --i) // for stability started from last index
    {
        aux[count[arr[i]] - 1] = arr[i]; // adding the elements in an temp array to sort the elements
        --count[arr[i]];                 // decresing the index of count by 1 and then adding the value at correct position --->(mandatory)
    }
    for (i = 0; i < n; ++i)
    {
        arr[i] = aux[i];
    }
}
int main()
{
    int arr[] = {1, 0, 2, 9, 2, 13, 29, 0, 32, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Sorting" << endl;
    display(arr, size);

    cout << "Array After Sorting" << endl;
    countsort(arr, size);
    display(arr, size);
}