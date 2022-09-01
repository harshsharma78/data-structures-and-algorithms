#include <bits/stdc++.h>
using namespace std;
vector<int> PosNegPair(int arr[], int n)
{
    vector<int> v, ans;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            v.push_back(arr[i]);
        else
            m[arr[i]]++;
    }
    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--) // reverse bcz the arr contains negative
    {
        int value = abs(v[i]); // making + to -
        if (m[value] > 0)
        {
            ans.push_back(v[i]);
            ans.push_back(value);
            m[value] -= 1; // to shift indexes for pairing
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 4, 2, -4, -3, 6, 3, 9, -6};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    v = PosNegPair(arr, size);

    cout << "The Positive and Negative Pairs of the Elements in an Array are --> " << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}