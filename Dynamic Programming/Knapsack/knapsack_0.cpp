#include <bits/stdc++.h>
using namespace std;

int dp[101][1001]; // if want to store locally then the it will dp[n+1][W+1] and this step is for the Memoization

// Knapsack ---> getting the Max Profit Problem from the Items given (wt[], val[])
// Types ---> 0/1 [item can only be added once in a knapsack], Unbounded [item can be added many times],
//            Fractional [item can also be added in fractions] *Fractional Knapsack is a part of Greedy not DP.

int knapsack(int wt[], int val[], int W, int n) // 0/1 -- Recursively and Memoization [Top-Down Approach]
{
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] <= W)
        return dp[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    // if the weight of the item is less than the total capacity then add that value and subtract it from the
    // total capacity and also remove that item from the window and return the max profit.

    // **For Memoization add dp[n][W] <--- this matrix

    else if (wt[n - 1] > W)
        return dp[n][W] = knapsack(wt, val, W, n - 1);
    // if the weight of the item is more than the total capacity then don't add and jump to next one
    return dp[n][W];
}

int Knapsack(int wt[], int val[], int W, int n) // Tabulation Method [Bottom-Up Approach] (Removing Recursive Calls)
{
    /*
    x-axis side is the W (j)
    y-axis side is the n (i)

    t[n][W] for n=0 W=0 i.e. 0th row and column filling is the initialization in the tabulation and it is similar to the base condition in the recursive approach
    */

    // Initialization/Base Condition --> i replaces n and j replaces W
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            // if the weight of the item is less than the total capacity then add that value and sub it from the
            // total capacity and also remove that item from the window and return the max profit.
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    memset(dp, -1, sizeof(dp));
    int n = sizeof(val) / sizeof(val[0]);
    cout << "Max Profit " << Knapsack(wt, val, W, n);
}