// place k elements such that minimum distance is maximised
#include <bits/stdc++.h>
using namespace std;
bool feasible(int arr[], int n, int mid, int k)
{
    int pos = arr[0];
    int elements = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - pos) >= mid)
        {
            pos = arr[i];
            elements++;

            if (elements == k)
                return true;
        }
    }
    return 0;
}
int LargestMinDist(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int left = 1;
    int right = arr[n - 1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (feasible(arr, n, mid, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
            right = mid;
    }
    return result;
}
int main()
{
    int arr[] = {1, 2, 5, 4, 6};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The Minimum Distance Maximised is " << LargestMinDist(arr, size, k) << endl;
}