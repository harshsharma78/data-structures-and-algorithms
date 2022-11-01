// word = apx
// trie (ele a) --> reference trie (ele p, flag = false) --> p's reference trie (ele x, flag = false)
//              --> x's reference trie (end of the string, flag = true)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26]; // 26 letters (A - Z || a - z)
    bool flag = false;

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
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word) // Inserts a new word in trie
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        if (node->isEnd())
            return true;
        return false;
    }
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};
int main()
{
    Trie trie;
    trie.insert("app");
    trie.insert("apple");
    trie.insert("apip");
    trie.insert("apasp");

    trie.search("ap") ? cout << "String is Present in the Trie" << endl : cout << "String is Absent in the Trie" << endl;
    trie.startsWith("ap") ? cout << "String Prefix is Present in the Trie" << endl : cout << "String Prefix is Absent in the Trie" << endl;
}