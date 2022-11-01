// Bit Manipulation in Tries
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
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
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--) // Bits are added from right to left
        {
            int bit = (num >> i) & 1; // Set a bit
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            // if (node->containsKey(!bit))
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i); // adding 1 in place of 0 and vice - versa
                node = node->get(1 - bit);
            }
            node = node->get(bit);
        }
        return maxNum;
    }
};
int maxXOR(vector<int> &arr1, vector<int> &arr2)
// int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    // for (int i = 0; i < n; i++)
    for (auto &it : arr1)
        trie.insert(it);

    int maxi = 0;
    // for (int i = 0; i < m; i++)
    for (auto &it : arr1)

        maxi = max(maxi, trie.getMax(it));

    return maxi;
}

int main()
{
    vector<int> arr1 = {6, 6, 0, 6, 8, 5, 6};
    vector<int> arr2 = {1, 7, 1, 7, 8, 0, 2};
    int n = arr1.size();
    int m = arr2.size();

    cout << maxXOR(arr1, arr2) << endl;
}