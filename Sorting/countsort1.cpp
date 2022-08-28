// count sort for negative values
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countsort(vector<int> &arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    int aux[arr.size()];
    int i;
    vector<int> count(range + 1);
    // memset(count, 0, sizeof(count));
    for (i = 0; i < arr.size(); ++i)
    {
        count[arr[i] - min]++; // counting the number of elements of arr[] ----> how many times an element occur
    }
    for (i = 1; i <= range; ++i)
    {
        count[i] += count[i - 1]; // for finding how many positions a number has occupied
    }
    // for (i = 0; i < n; i++)
    // {
    //     aux[count[arr[i]]] = arr[i]; // adding the elements in a temp array to sort the elements
    //     --count[arr[i]];             // decresing the index of count by 1 and then adding the value at correct position --->(mandatory)
    // }

    for (i = arr.size() - 1; i >= 0; --i) // for stability started from last index
    {
        aux[count[arr[i] - min] - 1] = arr[i]; // adding the elements in an temp array to sort the elements
        count[arr[i] - min]--;                 // decresing the index of count by 1 and then adding the value at correct position --->(mandatory)
    }
    for (i = 0; i < arr.size(); ++i)
    {
        arr[i] = aux[i];
    }
}
int main()
{
    vector<int> arr = {2, 9, -10, -3, -1, 2, 13, 29, 0, 32, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array Before Sorting" << endl;
    display(arr);

    cout << "Array After Sorting" << endl;
    countsort(arr);
    display(arr);
}