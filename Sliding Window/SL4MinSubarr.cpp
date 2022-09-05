// Smallest Subarray of size k with sum > x
#include <bits/stdc++.h>
using namespace std;

// Method 1---> Not Efficient
int MinSubarray(int arr[], int n, int x)
{
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > x)
                ans = min(ans, j - i + 1);
        }
    }
    return ans;
}

// Method 2---->Optimised
int MinSubArray(int arr[], int n, int x)
{
    int sum = 0;
    int start = 0; // start and end represents the two ENDS of the window size
    int end = 0;
    int minlen = n + 1; // false value if there are no subarrays
    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++]; // end reaches the END of window size
        }
        while (sum > x && start < n)
        {
            if (end - start < minlen)
            {
                minlen = end - start; // here we get our value with sum > x
            }
            sum -= arr[start++];
        }
    }
    return minlen;
}
int main()
{

    int arr[] = {1, 4, 45, 6, 0, 19};
    int n = 6;
    int x = 51;
    cout << " The Smallest Subarray of Size k with Sum > x is [Method 1]: " << MinSubarray(arr, n, x) << endl;

    int arr1[] = {1, 10, 5, 2, 7};
    int n1 = 5;
    int x1 = 9;
    int minlen = MinSubArray(arr, n1, x1);
    if (minlen == n1 + 1)
    {
        cout << "No Subarrays Found" << endl;
    }
    else
    {
        cout << " The Smallest Subarray of Size k with Sum > x is [Method 2]: " << minlen << endl;
    }
}