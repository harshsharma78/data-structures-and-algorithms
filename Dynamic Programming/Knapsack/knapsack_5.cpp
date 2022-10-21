// Count the Number of Subsets with a given difference
// Sum(s1) - Sum(s2) = difference (given)

// **Similar Question (but a slight variation (MUST)) ---> ***Target Sum Problem (Leetcode)

#include <bits/stdc++.h>
using namespace std;

// Initially, find the subsets with a sum equals to the given sum
int totalSubset(int a[], int n, int sum)
{
    int tab[n + 1][sum + 1];
    tab[0][0] = 1;

    for (int i = 1; i <= n; i++)
        tab[i][0] = 1;

    for (int j = 1; j <= sum; j++)
        tab[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    }
    return tab[n][sum];
}

int countSubsetDiff(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += arr[i];

    int sum_s1 = (diff + sum) / 2;
    return totalSubset(arr, n, sum_s1);
}
int main()
{
    int arr[] = {6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int difference = 0;
    cout << "Maximum Number of Subsets whose Sum is equals to the Difference --> " << countSubsetDiff(arr, n, difference);
}