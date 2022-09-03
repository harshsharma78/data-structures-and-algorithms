#include <iostream>
using namespace std;
int findPeakValue(int arr[], int n, int low, int high)
{
    int mid = (low + high) / 2;

    if (low > high)
        return -1;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
    {
        return arr[mid]; // For Value
                         // return mid;      // For Index
    }

    else if (mid > 0 && arr[mid - 1] > arr[mid])
        findPeakValue(arr, n, low, mid - 1);

    else
        findPeakValue(arr, n, mid + 1, high);
}
int main()
{
    int arr[] = {4, 20, 21, 7, 8, 9, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The Peak Value in an Array is " << findPeakValue(arr, size, 0, size - 1) << endl;
}