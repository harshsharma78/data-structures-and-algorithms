// Longest Complete String | Longest Word with all Prefixes
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26]; // 26 letters (A - Z || a - z)
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL); // a is represented by 0, b by 1 .... z by 26
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
    bool checkIfAllPrefixExists(string word)
    {
        Node *node = root;
        bool flag = true;
        for (int i = 0; i < (word.length() && flag); i++) // flag should be true
        // for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);

                // if(!node->isEnd()) return false;
            }
            else
                return false;
        }
        return flag;
    }
};
string completeString(vector<string> &str)
{
    Trie *trie = new Trie();

    for (auto word : str)
        trie->insert(word);

    string longest = "";

    for (auto word : str)
    {
        if (trie->checkIfAllPrefixExists(word))
        {
            if (word.size() > longest.size())
            {
                longest = word;
            }
            if (word.size() == longest.size() && word < longest) // lexicographically smallest
            {
                longest = word;
            }
        }
    }
    if (longest == "")
        return "None";
    return longest;
}
int main()
{
    Trie trie;
    vector<string> a = {"ninjaaa", "n", "ninjga", "ni", "nin"};

    // trie.insert("n");
    // trie.insert("nin");
    // trie.insert("ninja");
    // trie.insert("ninga");
    // trie.insert("ni");

    cout << "The Longest Complete String is " << completeString(a) << endl;
}
