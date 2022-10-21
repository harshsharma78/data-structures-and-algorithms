// LCS --> Longest Common Subsequence
// char x[] = "aggtab";
// char y[] = "gxtxayb";
// lcs = 4

#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int lcs(char *x, char *y, int m, int n)
{
    if (n == 0 || m == 0)
        return 0;

    if (x[m - 1] == y[n - 1])
        return lcs(x, y, n - 1, m - 1) + 1;
    else
        return max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
}
// Memoized Approach
int LCS(char *x, char *y, int m, int n)
{
    int tab[n + 1][m + 1];
    memset(tab, -1, sizeof(tab));

    if (tab[n][m] != -1)
        return tab[n][m];

    if (x[m - 1] == y[n - 1])
        return tab[n][m] = lcs(x, y, n - 1, m - 1) + 1;
    else
        return tab[n][m] = max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
}
// Pure Dynamic Programming Approach
int lCS(char *x, char *y, int m, int n)
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
                tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
        }
    }
    return tab[m][n];
}
void printLCS(string x, string y, int m, int n)
{
    int tab[n + 1][m + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // Initialization Combined
                tab[i][j] = 0;

            else if (x.at(i - 1) == y.at(j - 1))
                tab[i][j] = tab[i - 1][j - 1] + 1;
            else
                tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
        }
    }
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcs.push_back(x[i - 1]); // or j-1
            i--;
            j--;
        }
        else if (tab[i - 1][j] > tab[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(lcs.begin(), lcs.end());
    cout << "LCS of " << x << " and " << y << " is " << lcs << endl;
}
int main()
{
    char a[] = "axcy";
    char b[] = "adxcpy";
    int m = strlen(a);
    int n = strlen(b);
    cout << "Longest Common Subsequence is " << lcs(a, b, m, n) << endl;

    string x = "gksrek";
    string y = "geeksforgeeks";
    // string x = "axy";
    // string y = "adxcpy";
    int s = x.size();
    int t = y.size();
    printLCS(x, y, s, t);
}