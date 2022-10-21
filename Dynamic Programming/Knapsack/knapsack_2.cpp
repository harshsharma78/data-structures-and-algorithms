// Equal Sum Partition Problem
// This problem has a condition that if an array contains two sets having same sum i.e. S1=S2 within the same array
#include <bits/stdc++.h>
using namespace std;

bool isSubSetsum(int arr[], int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j < arr[i - 1])
                subset[i][j] = subset[i - 1][j];

            if (j >= arr[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
        }
    }
    return subset[n][sum];
}
bool isEqualSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    if (sum % 2 == 0)
    {
        return isSubSetsum(arr, n, sum / 2);
    }
}
int main()
{
    int set[] = {3, 1, 6, 5, 2};
    int sum = 7;
    int n = sizeof(set) / sizeof(set[0]);

    if (isEqualSum(set, n) == true)
        printf("Found subsets with Equal Sum");
    else
        printf("No subset with Equal Sum");
    return 0;
}
