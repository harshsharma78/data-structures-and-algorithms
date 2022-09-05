#include <bits/stdc++.h>
using namespace std;

int maxsum(int arr[], int n, int k)
{
    int res = 0;
    int sum;
    for (int i = 0; i < k; i++)
    {
        res += arr[i];
    }
    sum = res;
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        res = max(res, sum);
    }
    return res;
}
int isPerfect(int num)
{
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == num / i)
            {
                sum += i;
            }
            else
                sum += i + num / i;
        }
    }
    if (sum == num && num != 1)
        return true;
    return false;
}
int findPerfects(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (isPerfect(arr[i]))
        {
            arr[i] = 1;
            // cout << arr[i] << " ";
        }
        else
            arr[i] = 0;
    }
    return maxsum(arr, n, k);
}
int main()
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    // int arr[] = {1, 2, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << findPerfects(arr, size, k);
}