#include <bits/stdc++.h>
using namespace std;

bool hasSumX(int *arr, int n, int x)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        int key = itr->first;
        int val = itr->second;
        int pair = x - key; // *****
        if (pair == key)
        {
            if (val > 1)
                return true;
        }
        else
        {
            if (m.find(pair) != m.end())
                return true;
        }
    }
    return false;
}
bool subArrayExists(int arr[], int n) // sub-array with sum 0 exists or not
{
    unordered_set<int> s;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == 0)
            return true;

        if (s.find(prefix_sum) != s.end())
            return true;
        s.insert(prefix_sum);
    }
    return false;
}
vector<string> winner(string votes[], int n)
{
    unordered_map<string, int> umap;
    for (int i = 0; i < n; i++)
        umap[votes[i]]++;
    int max_votes = 0;
    string name = "";
    for (auto itr = umap.begin(); itr != umap.end(); itr++)
    {
        string key = itr->first;
        int votes = itr->second;

        if (votes > max_votes)
        {
            max_votes = votes;
            name = key;
        }
        else if (votes == max_votes)
        {
            if (key < name)
                name = key;
        }
    }
    vector<string> result;
    result.push_back(name);

    string v = to_string(max_votes);
    result.push_back(v);

    return result;
}

int main()
{
    string candidates[] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie", "john", "johnny", "jamie", "johnny", "john"};

    vector<string> v;
    v = winner(candidates, 13);
    cout << "The Winner is --> ";
    for (auto i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "votes";

    int arr[] = {10, 10, -3, -7, 2, 70, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    // cout << "Are there two Elements in an Array whose Sum = X --> " << hasSumX(arr, size, 20);
    // cout << "Are there Elements in an Array whose Sum = 0 --> " << subArrayExists(arr, size);
}
