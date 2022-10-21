// Coin Change Problem - 2 --> Minimum Number of Coins required for given Sum
#include <bits/stdc++.h>
using namespace std;
int coinChange(int coin[], int n, int sum)
{
    int tab[n + 1][sum + 1];

    for (int i = 1; i <= n; i++)
        tab[i][0] = 0;

    for (int j = 0; j <= sum; j++)
        tab[0][j] = INT_MAX - 1;
    for (int j = 1; j <= sum; j++)
        tab[0][j] = INT_MAX - 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
                tab[i][j] = min(tab[i - 1][j - coin[i - 1]] + 1, tab[i - 1][j]); // INT_MAX - 1 + 1 = INT_MAX

            if (coin[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
        }
    }
    return tab[n][sum];
}
int main()
{
    int coin[] = {1, 2, 8};
    int sum = 8;
    int n = sizeof(coin) / sizeof(coin[0]);
    cout << "Minimum Number of Coins " << coinChange(coin, n, sum);
}