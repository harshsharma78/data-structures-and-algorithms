// also known as bucket sort
// it includes positions like ones tens ...
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
int maxi(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countsort(int arr[], int n, int pos)
{
    int range = 10; // for numerical values
    int i, count[10];
    int aux[n];
    memset(count, 0, sizeof(count));
    for (i = 0; i < n; i++)
    {
        ++count[(arr[i] / pos) % 10];
    }
    for (i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        aux[count[(arr[i] / pos) % 10] - 1] = arr[i];
        --count[(arr[i] / pos) % 10];
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = aux[i];
    }
}
void radixsort(int arr[], int n)
{
    int max = maxi(arr, n);
    for (int pos = 1; (max / pos) > 0; pos *= 10)
    {
        countsort(arr, n, pos);
    }
}
int main()
{
    int arr[] = {12, 2, 132, 29, 1, 32, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array Before Sorting" << endl;
    display(arr, size);

    cout << "Array After Sorting" << endl;
    radixsort(arr, size);
    display(arr, size);
}