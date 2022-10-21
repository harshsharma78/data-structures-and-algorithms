// Minimum Number of Deletion in a String to make it a Palindrome

#include <bits/stdc++.h>
using namespace std;

int lCS(string x, string y, int m, int n)
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
    return tab[m][n];
}
int lps(string x)
{
    int m = x.size();
    string y = string(x.rbegin(), x.rend());
    int lps = lCS(x, y, m, m);
    return lps;
}
int minDel(string x, int m)
{
    return m - lps(x); // Length of String - LPS
}
int main()
{
    string x = "abcsda";
    int s = x.size();
    cout << "Minimum Number of Deletions required in a String to make it a Palindrome are " << minDel(x, s);
}