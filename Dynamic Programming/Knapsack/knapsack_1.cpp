// Subset Sum Problem
#include <bits/stdc++.h>
using namespace std;
// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    bool subset[n + 1][sum + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            // This is a formula which acquires its values from the initialization process and helps to fill the 
            // DP Table
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
            cout << subset[i][j] << "  ";
        cout << endl;
    }

    // return subset[n][sum];
}

int main()
{
    int set[] = {3, 4, 5, 2};
    int sum = 6;
    int n = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}
