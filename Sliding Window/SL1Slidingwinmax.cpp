#include <bits/stdc++.h>
#include <deque>
using namespace std;
void Sliding_Window_Maximum(vector<int> &arr, int n, int k)
{
    deque<int> dq(k);
    int i;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() and arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i); // we are dealing with index
    }
    for (i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";

        while (!dq.empty() and dq.front() <= i - k) // removing the elements which are out of window range
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
}
int main()
{
    vector<int> arr = {12, 1, 78, 90, 57, 89, 56};
    int n = arr.size();
    int k = 3;
    Sliding_Window_Maximum(arr, n, k);
}
// {
//     int k = 3; // window
//     vector<int> a = {12, 1, 78, 90, 57, 89, 56};
//     int n = a.size(); // size of array
//     multiset<int, greater<int>> ms;
//     vector<int> ans;
//     // cout << "Enter the size of the Sliding Window: ";
//     // cin >> k;
//     // cout << "Enter the size of an Array: ";
//     // cin >> n;
//     // for (auto &i : a)
//     //     cin >> i;
//
//     for (int i = 0; i < k; i++)
//     {
//         ms.insert(a[i]); // inserting the elements till the window limit
//     }
//     ans.push_back(*ms.begin());
//     for (int i = k; i < n; i++)
//     {
//         ms.erase(ms.lower_bound(a[i - k])); // erasing the smaller elements or those which are out of the window size
//         ms.insert(a[i]);                    // inserting the next elements
//         ans.push_back(*ms.begin());
//     }
//     for (auto i : a)
//     {
//         cout << i << " ";
//     }
