// Unbounded Knapsack
// Rod Cutting Problem is also same.
#include <bits/stdc++.h>
using namespace std;

int unboundKnapsack(int wt[], int val[], int n, int sum)
{
    int tab[n + 1][sum + 1];
    memset(tab, -1, sizeof(tab));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 || j == 0)
                tab[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (wt[i - 1] <= j)
                tab[i][j] = max(val[i - 1] + tab[i][j - wt[i - 1]], tab[i - 1][j]);

            if (wt[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
        }
    }
    return tab[n][sum];
}
int main()
{
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int W = 100;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "Max Profit " << unboundKnapsack(wt, val, n, W);
}
