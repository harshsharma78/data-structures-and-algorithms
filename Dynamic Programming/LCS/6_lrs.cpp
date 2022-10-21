// Longest Repeating Subsequence
// Approach --> we are taking same string twice and the indices of the repeating characters should be cross matched
// and shouldn't be same

/* for e.g., string x = abcadea
                        1234567

             string y = abcadea
                        1234567
   'a' at 1 in x and 'a' at 4 in y should be included and 'a' at 1 in x and 'a' at 1 in y shouldn't be included 
    i.e. i should != j */

#include <bits/stdc++.h>
using namespace std;
int lrs(string x, string y, int m, int n)
{
    int tab[n + 1][m + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // Initialization Combined
                tab[i][j] = 0;

            else if (x.at(i - 1) == y.at(j - 1) && i != j)
                // i != j bcz there should be cross matching b/w the strings' index
                // i == j means we are taking the same index of the string again i.e. (e.g., abcd --> we are taking 'a' twice or thrice ...)
                tab[i][j] = tab[i - 1][j - 1] + 1;
            else
                tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
        }
    }
    return tab[m][n];
}
int main()
{
    string x = "aabebcdd";
    int m = x.size();
    cout << "The Length of Longest Repeating Subsequence is " << lrs(x, x, m, m);
}