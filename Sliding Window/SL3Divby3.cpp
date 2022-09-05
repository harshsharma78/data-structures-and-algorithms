// Form Number Divisible by 3
#include <bits/stdc++.h>
using namespace std;
void NumDivBy3(int arr[], int n, int k)
{
    pair<int, int> result;
    int sum = 0;
    int i;
    bool div = false;

    for (i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum % 3 == 0)
    {
        result = make_pair(0, i - 1);
        div = true;
    }

    for (i = k; i < n; i++)
    {
        if (div == true)
        {
            break;
        }
        sum += arr[i] - arr[i - k];
        if (sum % 3 == 0)
        {
            result = make_pair(i - k + 1, i);
            div = true;
        }
    }

    if (div == false)
    {
        result = make_pair(-1, 0);
    }
    if (result.first == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        for (i = result.first; i <= result.second; i++)
        {
            cout << arr[i] << " ";
        }
    }
}
int main()
{
    int arr[] = {84, 23, 45, 1, 56, 82};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    NumDivBy3(arr, n, k);
}