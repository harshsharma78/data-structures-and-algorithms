// Max sumsubarray of size k with sum < x
#include <bits/stdc++.h>
using namespace std;
void MaxSumSubarray(int arr[], int n, int k, int x)
{
    int sum = 0;
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum < x)
    {
        result = sum;
    }
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];

        if (sum < x)
        {
            result = max(result, sum);
        }
    }
    cout << result << " " << endl;
}
int main()
{
    int arr[] = {-5, 8, 7, 2, 10, 1, 20, -4, 6, 9};
    int k = 5;
    int x = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The Maximum Sum in Subarray with Size k and Sum < x is: ";
    MaxSumSubarray(arr, n, k, x);
}