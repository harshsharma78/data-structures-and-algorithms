// Minimum Number of Insertion or Deletion to Convert String A to String B
// Approach --> String A -- LCS -- String B  ----> Insertion , Deletion
//               "heap"    "ea"     "pea"            1(p)    ,  2(hp)

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
void minInsDel(string x, string y)
{
    int m = x.size();
    int n = y.size();
    int lcs = lCS(x, y, m, n);
    cout << "Minimum Number of Deletions are " << m - lcs << endl;
    cout << "Minimum Number of Insertions are " << n - lcs << endl;
}
int main()
{
    string x = "heap";
    string y = "pea";
    minInsDel(x, y);
}