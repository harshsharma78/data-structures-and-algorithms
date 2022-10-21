// *****Scrambled String Problem (can't contain empty string)
// great = great
// great = eatgr
// great = rgeat and so on

// Approach :- Make Binary Tree and try to SWAP the NON_LEAF Nodes and if the first k - half of the String1 = last
//             half of the String2 (which is afer the k - breaks) && last half of the String1 (after the k -
//             breaks) = first half of the String2 (before the k - breaks) then it is a Scrambled String.

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;
bool isScrambled(string a, string b)
{
    if (a.compare(b) == 0)
        return true;

    if (a.length() <= 1)
        return false;

    int n = a.length();
    bool flag = false;

    for (int i = 1; i <= n - 1; i++)
    {
        bool cond1 = false;
        bool cond2 = false;

        if (isScrambled(a.substr(0, i), b.substr(n - i, i)) &&
            isScrambled(a.substr(i, n - i), b.substr(0, n - i)))
            cond1 = true;

        else if (
            isScrambled(a.substr(0, i), b.substr(0, i)) &&
            isScrambled(a.substr(i, n - i), b.substr(i, n - i)))
            cond2 = true;

        if (cond1 || cond2)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
bool isScrambledMemo(string a, string b)
{

    if (a.compare(b) == 0 || a.length() == 0 || a == b)
        return true;

    if (a.length() <= 1)
        return false;

    if (a.length() > b.length() || b.length() > a.length())
        return false;

    // Check for Anagram
    string copy_a = a;
    string copy_b = b;
    sort(copy_a.begin(), copy_a.end());
    sort(copy_b.begin(), copy_b.end());
    if (copy_a != copy_b)
        return false;

    string key = (a + " " + b); // string a_string b -- unique key formation

    // a.push_back(' ');
    // a.append(b); // string a_string b -- unique key formation

    if (mp.find(key) != mp.end())
        return mp[key];

    int n = a.length();
    bool flag = false;

    for (int i = 1; i <= n - 1; i++)
    {
        bool cond1 = false;
        bool cond2 = false;

        if (isScrambled(a.substr(0, i), b.substr(n - i, i)) &&
            isScrambled(a.substr(i, n - i), b.substr(0, n - i)))
            cond1 = true;

        if (isScrambled(a.substr(0, i), b.substr(0, i)) &&
            isScrambled(a.substr(i, n - i), b.substr(i, n - i)))
            cond2 = true;

        if (cond1 || cond2)
        {
            flag = true;
            break;
        }
    }
    return mp[key] = flag;
}
int main()
{
    string a = "coder";
    string b = "coder";

    if (a.length() == 0 && b.length() == 0)
        cout << "This is a Scrambled String" << endl;

    mp.clear();
    isScrambledMemo(a, b) ? cout << "This is a Scrambled String" << endl : cout << "This is not a Scrambled String" << endl;
}
