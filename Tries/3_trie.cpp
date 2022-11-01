// Count Distinct Substrings in a String
// for abab, Distinct Substrings are 8
// a, ab, aba, abab, b, bab, ba, " "
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26]; // 26 letters (A - Z || a - z)

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL; // a is represented by 0, b by 1 .... z by 26
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};
int cntDistinctSubstrings(string &s)
{
    int cnt = 0;
    Node *root = new Node();
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(s[j]))
            {
                node->put(s[j], new Node());
                cnt++;
            }
            node = node->get(s[j]);
        }
    }
    return cnt + 1;
}

int main()
{
    string s = "abab";
    cout << "The Distinct Substrings in a String " << s << " are " << cntDistinctSubstrings(s);
}