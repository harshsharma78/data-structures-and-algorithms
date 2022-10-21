// Minimum Subset Sum Difference
// sum(s1) - sum(s2) = minimimum difference
// e.g., {1, 5, 6} - {11} = 1

#include <bits/stdc++.h>
using namespace std;

int minSubsetSum(int arr[], int n)
{
    //  Finding those elements which can't be included using (Equal Sum Problem)
    // e.g., from the range 0 to 10 ; 4, 5, 6 can't be included
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

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
            if (arr[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            if (arr[i - 1] <= j)
                tab[i][j] = tab[i - 1][j] || tab[i - 1][j - arr[i - 1]];
        }
    }
    // Finding the miminimum difference
    int diff = INT_MAX;
    for (int i = sum / 2; i >= 0; i++)
    // The last row of the DP Table and from the half so that sum(s2) should be greater.
    {
        if (tab[n][i] == true)
        {
            diff = sum - (2 * i);
            break;
        }
    }
    return diff;
}
int main()
{
    // int arr[] = {3, 1, 4, 2, 2, 1};
    int arr[] = {4, 4, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The Minimum Difference between Two Sets is " << minSubsetSum(arr, n) << endl;
}