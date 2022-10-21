// Shortest Common Super Sequence
// char x[] = "geek";
// char y[] = "eke";
// ss = geekeke
// scss = geeke

#include <bits/stdc++.h>
using namespace std;

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
int scss(char *x, char *y, int m, int n)
{
    return m + n - lCS(x, y, m, n);
}
int printSCSS(string x, string y, int m, int n)
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
    string scss = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            scss.push_back(x[i - 1]); // or j-1
            i--;
            j--;
        }
        else if (tab[i - 1][j] > tab[i][j - 1])
        {
            scss.push_back(x[i - 1]);
            i--;
        }
        else
        {
            scss.push_back(y[j - 1]);
            j--;
        }
    }
    // It is not necessary that everytime we reach t(0,0) in SCSS. So,
    while (i > 0)
    {
        scss.push_back(x[i - 1]);
        i--;
    }
    while (j > 0)
    {
        scss.push_back(y[j - 1]);
        j--;
    }
    reverse(scss.begin(), scss.end());
    cout << "SCSS of " << x << " and " << y << " is " << scss << endl;
}
int main()
{
    // char x[] = "geek";
    // char y[] = "eke";
    // int m = strlen(x);
    // int n = strlen(y);
    // cout << "Shortest Common Super Sequence is " << scss(x, y, m, n) << endl;

    string a = "hello";
    string b = "geek";
    int s = a.size();
    int t = b.size();
    printSCSS(a, b, s, t);
}
