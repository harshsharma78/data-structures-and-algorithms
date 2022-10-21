// Sequence Pattern Matching
// A = axy
// B = adxcpy
// is A present in B
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
// bool SPM(string x, string y,int m,int n)
// {

//     int lcs = lCS(x, y, m, n);

//     if (lcs == m)
//         return true;
//     else
//         return false;
// }
bool subPM(string x, string y, int m, int n)
{
    int tab[m + 1][n + 1];
    memset(tab, -1, sizeof(tab));

    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (tab[m][n] != -1)
        return tab[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (x[i - 1] == y[j - 1])
                tab[i][j] = subPM(x, y, i - 1, j - 1);
            tab[i][j] = subPM(x, y, i, j - 1); // if last characters are not matching
        }
    }
    return tab[m][n];
}
bool spm(string x, string y, int m, int n)
{
    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (x[m - 1] == y[n - 1])
        return spm(x, y, m - 1, n - 1);

    return spm(x, y, m, n - 1); // if last characters are not matching
}
bool itSPM(string x, string y, int m, int n)
{
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {

        if (x[j] == y[i])
            j++;
    }
    return (j == m);
}
int main()
{
    string a = "gksrek";
    string b = "geeksforgeeks";
    int m = a.length();
    int n = b.length();
    subPM(a, b, m, n)
        ? cout << "String A is present in B" << endl
        : cout << "String A is not present in B" << endl;
}