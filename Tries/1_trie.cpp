#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void reduceEnd()
    {
        cntEndWith--;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
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
            node->increasePrefix();
        }
        node->increaseEnd(); // When String length Completes then count increases by 1
    }
    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getEnd();
    }
    int countWordsStartsWith(string &prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (node->containsKey(prefix[i]))
                node = node->get(prefix[i]);
            else
                return 0;
        }
        return node->getPrefix();
    }
    void erase(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
                return;
        }
        node->reduceEnd();
        // String Count also decreases i.e. if we have two Strings (apps, apps) and if we remove one then String
        // count reduces
    }
};
int main()
{
    Trie trie;
    string a = "ap";
    string e = "apip";

    trie.insert("app");
    trie.insert("apple");
    trie.insert("apip");
    trie.insert("apasp");

    cout << "There is/are " << trie.countWordsEqualTo(a) << " String(s) Present in the Trie = " << a << endl;
    cout << "There is/are " << trie.countWordsStartsWith(a) << " String Prefix in the Trie = " << a << endl;

    trie.erase("apip");

    cout << "There is/are " << trie.countWordsEqualTo(a) << " String(s) Present in the Trie = " << a << endl;
    cout << "There is/are " << trie.countWordsStartsWith(a) << " String Prefix in the Trie = " << a << endl;
}