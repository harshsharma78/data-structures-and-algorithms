// Count Subsets with a given Sum
#include <iostream>
using namespace std;

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
int main()
{
    int a[] = {3, 3, 3, 3};
    int sum = 6;
    int n = 4;
    cout << totalSubset(a, n, sum);
}