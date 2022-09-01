// hashing can be done with the help of unordered map or unordered set
// these are key and value pairs
// unordered_map<int, int> u;
//               key, value
//       temp->first, temp->second

#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(int arr[], int n)
{
    unordered_map<int, int> u;
    for (int i = 0; i < n; i++)
        u[arr[i]]++;
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        auto temp = u.find(key);
        if (temp->second == 1)
            return key;
    }
    return 0;
}
int firstRepeated(int *arr, int n)
{
    unordered_map<int, int> u;
    for (int i = 0; i < n; i++)
        u[arr[i]]++;
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        auto temp = u.find(key);
        if (temp->second > 1)
            return key;
    }
    return -1;
}
void doUnion(int *a, int n, int *b, int m)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (int j = 0; j < m; j++)
        s.insert(b[j]);

    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " ";
}
int elementsInIntersection(int *a, int n, int *b, int m)
{
    unordered_set<int> s;
    int count = 0;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    for (int i = 0; i < m; i++)
    {
        int key = b[i];
        if (s.find(key) != s.end())
        {
            count++;
            s.erase(key);
        }
    }
    return count;
}
int main()
{
    // int arr[] = {1, 3, 5, 3, 4, 3, 5, 6};
    // int size = sizeof(arr) / sizeof(arr[0]);

    int a[] = {1, 2, 5, 6, 2, 3, 5, 7, 3};
    int b[] = {2, 4, 5, 6, 8, 9, 4, 6, 5, 4};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    // cout << "The First Non-repeating Element in an Array is --> " << firstNonRepeating(arr, size);
    // if result is '0' then no repeating element is present

    // cout << "The First Repeating Element in an Array is --> " << firstRepeated(arr, size);

    // cout << "Arrays after Union are--> ";
    // doUnion(a, n, b, m);

    cout << "Arrays after Intersection are --> " << elementsInIntersection(a, n, b, m);
}