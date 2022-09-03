#include <bits/stdc++.h>
using namespace std;
int SearchinRotatedarray1(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2; // (low + (high - low))/2

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] >= arr[low])
        {
            if (arr[mid] >= target && arr[low] <= target)
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= target && arr[high] >= target)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    return -1;
}
int SearchinRotatedarray2(int arr[], int low, int high, int n, int target)
{

    int mid = (low + high) / 2; // (low + (high - low))/2

    if (arr[mid] == target)
        return mid;

    else if (arr[mid] >= arr[low])
    {
        if (arr[mid] >= target && target >= arr[low])
        {

            SearchinRotatedarray2(arr, mid - 1, low, n, target);
        }
        else

            SearchinRotatedarray2(arr, mid + 1, high, n, target);
    }

    else
    {
        if (arr[mid] <= target && target <= arr[high])
        {

            SearchinRotatedarray2(arr, mid + 1, high, n, target);
        }
        else

            SearchinRotatedarray2(arr, mid - 1, low, n, target);
    }
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3, 4, 5};
    int ar[] = {4, 5, 6, 7, 1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    cout << "Searching in The Sorted but Roatated Array [Method 1] " << SearchinRotatedarray1(arr, target) << endl;

    cout << "Searching in The Sorted but Roatated Array [Method 2] "
         << SearchinRotatedarray2(ar, 0, size - 1, size, target) << endl;
}