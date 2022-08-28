#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// merge two unsorted arrays

void merge(int arr1[], int arr2[], int arr3[], int m, int n)
{
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    int k = 0;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < m)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}

int main()
{
    int arr1[] = {0, 12, 2, 13, 29, 0, 32, 3};
    int arr2[] = {0, 12, 2, 13, 29, 0, 32, 3};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    int arr3[m + n];

    cout << "Array After Sorting" << endl;
    merge(arr1, arr2, arr3, m, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << arr3[i] << " ";
    }
}