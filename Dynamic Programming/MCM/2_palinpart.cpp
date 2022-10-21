// Palindrome Partitioning
// string str = abcbd
// Partitions required to make it a Palindrome in a such a way that every String present in this
// "String str" should be a Palindrome
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    if (i == j || i > j)
        return true;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int makePalindrome(string s, int i, int j)
// How many Partitions are required to make it a Palindrome in a such a way that every String present in this
// String should be a Palindrome
{
    if (i >= j)
        return 0;

    if (isPalindrome(s, i, j))
        return 0;

    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = makePalindrome(s, i, k) + makePalindrome(s, k + 1, j) + 1;
        // +1 for the no. of partitions i.e. A1's ans and A2's ans +1 for the partition b/w them to make it
        // Palindrome
        if (tempans < mini)
            mini = tempans;
    }
    return mini;
}
int make_Palindrome(string s, int i, int j)
// How many Partitions are required to make it a Palindrome in a such a way that every String present in this
// String should be a Palindrome
{
    int tab[i + 1][j + 1];
    memset(tab, -1, sizeof(tab));

    if (i >= j)
        return 0;

    if (tab[i][j] != -1)
        return tab[i][j];

    if (isPalindrome(s, i, j))
        return 0;

    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = makePalindrome(s, i, k) + makePalindrome(s, k + 1, j) + 1;
        // +1 for the no. of partitions i.e. A1's ans and A2's ans +1 for the partition b/w them to make it
        // Palindrome
        if (tempans < mini)
            mini = tempans;
    }
    return tab[i][j] = mini;
}
// int make_Palindrome_Opti(string s, int i, int j)
// // How many Partitions are required to make it a Palindrome in a such a way that every String present in this
// // String should be a Palindrome
// {
//     int tab[i + 1][j + 1];
//     memset(tab, -1, sizeof(tab));

//     if (i >= j)
//         return 0;

//     if (tab[i][j] != -1)
//         return tab[i][j];

//     if (isPalindrome(s, i, j))
//         return 0;

//     int mini = INT_MAX;
//     int left = INT_MAX, right = INT_MAX;

//     for (int k = i; k < j; k++)
//     {
//         if (tab[i][k] != -1)
//             left = tab[i][k];
//         else
//         {
//             left = makePalindrome(s, i, k);
//             tab[i][k] = left;
//         }

//         if (tab[k + 1][j] != -1)
//             right = tab[k + 1][j];
//         else
//         {
//             right = makePalindrome(s, k + 1, j);
//             tab[k + 1][j] = right;
//         }
//         int tempans = left + right + 1;
//         // +1 for the no. of partitions i.e. A1's ans and A2's ans +1 for the partition b/w them to make it
//         // Palindrome
//         if (tempans < mini)
//             mini = tempans;
//     }
//     return tab[i][j] = mini;
// }

int main()
{
    string s = "abcde";
    int size = s.size();
    cout << "Total Number of Partitions to make String Palindrome --> " << make_Palindrome(s, 0, size - 1);
}