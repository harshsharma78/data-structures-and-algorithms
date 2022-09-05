// Subarray of size k have Palindromic Concatenation or not
#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(int n)
{
    int temp = n;
    int num = 0;
    while (temp > 0)
    {
        num = num * 10 + temp % 10;
        temp = temp / 10;
    }
    if (num == n)
    {
        return true;
    }
    return false;
}
int PalindromeConcatenation(vector<int> arr, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i]; // 2351
    }
    if (ispalindrome(num))
    {
        return 0;
    }
    for (int i = k; i < arr.size(); i++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[i]; // 3511...5115...
        if (ispalindrome(num))
        {
            return (i - k + 1); // where concatenation found
        }
    }
    return -1;
}
bool palindrome(vector<int> arr, int i, int j)
{
    while (i < j)
    {
        if (arr[i] != arr[j])
            return false;

        i++;
        j--;
    }
    return true;
}
int findSubarray(vector<int> arr, int k)
{
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i <= (n - k); i++)
    {
        if (palindrome(arr, i, (i + k - 1)))
        {
            return i;
        }
    }
}
int main()
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    // int arr1[] = {5, 2, 5, 5, 1, 5};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = PalindromeConcatenation(arr, k);
    if (ans == -1)
    {
        cout << " Palindromic Concatenation not Found" << endl;
    }
    else
    {
        cout << " The Palindromic Concatenation in the Subarray of size k is: ";
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int res = findSubarray(arr, k);
    if (res == -1)
    {
        cout << " Palindromic Concatenation not Found" << endl;
    }
    else
    {
        for (int i = res; i < res + k; i++)
        {
            // cout << " The Palindromic Concatenation in the Subarray of size k is: " << arr1[i] << " ";
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}