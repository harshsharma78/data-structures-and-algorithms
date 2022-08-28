#include <bits/stdc++.h>
using namespace std;

long long merge(int arr[], int left, int mid, int right)
{
    long long inv = 0;
    int i, j, k;
    int n1 = mid - left + 1; //size
    int n2 = right - mid;
    int a[n1]; //temp
    int b[n2]; //arrays
    for (i = 0; i < n1; i++)
    {
        a[i] = arr[left + i];
    }
    for (i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            inv += n1 - i; // important --->because a[i] becomes > b[j] so there is inversion so to compare with all the elements this step
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv;
}
long long mergesort(int arr[], int left, int right)
{
    long long inv = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        inv += mergesort(arr, left, mid);
        inv += mergesort(arr, mid + 1, right);
        inv += merge(arr, left, mid, right);
    }
    return inv;
}
int main()
{
    int size;
    cout << "Enter the Size of an Array" << endl;
    cin >> size;
    int arr[size];
    size = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter the Elements of an Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "The Total Number of Inversions are " << mergesort(arr, 0, size - 1);
}