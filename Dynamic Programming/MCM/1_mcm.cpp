// Matrix Chain Multiplication
// Ques - Multiply Matrices by putting brackets b/w them in such a way that it should give Minimum Cost
// arr[] = {20, 30, 40, 50}
// Ai Matrix = arr[k-1] * arr[k] --> For Base Condition

/* General Format :-

-> mcm(arr[]/ string, i, j,( any other variable/container(if any))) --> General Function

-> Base Condition (position of i and j)
-> k - loop Condition (k = what position of i; k </<= what position of j; k++/k+=2/k+=3...)
-> temp_ans (container variable)
-> min/max/..or any other fun(ans,tempans) (This fun can be a variable, STL function, etc.)

*/
#include <bits/stdc++.h>
using namespace std;

int mcm(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        // arr[i - 1] * arr[k] * arr[j] --> This is the Cost which comes after Multiplying mcm (A1), mcm (A2) i.e.
        // A1's ans * A2's ans = arr[i - 1] * arr[k] * arr[j] (Cost)
        if (tempans < mini)
            mini = tempans;
    }
    return mini;
}
int MCM(int arr[], int i, int j)
{
    int tab[i + 1][j + 1];
    memset(tab, -1, sizeof(tab));

    if (tab[i][j] != -1)
        return tab[i][j];

    if (i >= j)
        return 0;

    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int tempans = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        // arr[i - 1] * arr[k] * arr[j] --> This is the Cost which comes after Multiplying mcm (A1), mcm (A2) i.e.
        // A1's ans * A2's ans = arr[i - 1] * arr[k] * arr[j] (Cost)
        if (tempans < mini)
            mini = tempans;
    }
    return tab[i][j] = mini;
}
int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    // int arr[] = {10, 10, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Cost is " << MCM(arr, 1, n - 1);
}
