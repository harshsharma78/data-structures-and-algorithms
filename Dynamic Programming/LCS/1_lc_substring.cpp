// Longest Common Substring
// char x[] = "aggtab";
// char y[] = "aggxab";
// lc_substring = 3 (agg)
#include <bits/stdc++.h>
using namespace std;

int lcSubstring(char *x, char *y, int m, int n)
{
    int tab[n + 1][m + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // Initialization Combined
                tab[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
                tab[i][j] = tab[i - 1][j - 1] + 1;
            else
                tab[i][j] = 0;
        }
    }
    return tab[m][n];
}
int main()
{
    char x[] = "harsh";
    char y[] = "sharma";
    int m = strlen(x);
    int n = strlen(y);
    cout << "Longest Common Subsequence is " << lcSubstring(x, y, m, n);
}