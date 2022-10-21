// Coin Change Problem - 1 --> Find Maximum Number of Ways
#include <bits/stdc++.h>
using namespace std;

int coinChange(int coin[], int n, int value)
{
    int tab[n + 1][value + 1];

    tab[0][0] = 1;
    for (int i = 1; i <= n; i++)
        tab[i][0] = 1;

    for (int j = 1; j <= value; j++)
        tab[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= value; j++)
        {
            if (coin[i - 1] <= j)
                tab[i][j] = tab[i - 1][j] + tab[i][j - coin[i - 1]];
            else
                tab[i][j] = tab[i - 1][j];
        }
    }
    return tab[n][value];
}
int main()
{
    //int val[] = {60, 100, 120};
    int coin[] = {1, 2, 3};
    int sum = 8;
    // memset(dp, -1, sizeof(dp));
    int n = sizeof(coin) / sizeof(coin[0]);
    cout << "Maximum Number of Combinations " << coinChange(coin, n, sum);
}