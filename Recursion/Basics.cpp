#include <bits/stdc++.h>
using namespace std;

void ReverseAnArray(int arr[], int n, int index)
{
    if (index >= n / 2)
        return;

    // int temp = arr[n - index - 1];
    // arr[n - index - 1] = arr[index];
    // arr[index] = temp;
    swap(arr[index], arr[n - index - 1]);

    ReverseAnArray(arr, n, index + 1);
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int binarysearch(int arr[], int low, int high, int ele)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (ele == arr[mid])
            return mid;

        if (ele < arr[mid])
            return binarysearch(arr, low, mid - 1, ele);

        else
            return binarysearch(arr, mid + 1, high, ele);
    }
    return -1;
}
bool StringPalindrome(char arr[], int n, int index)
{
    if (index >= n / 2)
    {
        return true;
    }
    if (arr[index] == arr[n - index - 1])
        return StringPalindrome(arr, n, index + 1);
    return false;
}

int main()
{
    int arr[] = {1, 5, 7, 9, 10};
    char str[] = {"MadaM"};
    int n = strlen(str);

    // int mid = (low + high) / 2;
    // printarray(arr, n);
    // ReverseAnArray(arr, n, 0);
    // printarray(arr, n);

    // int BSResult = binarysearch(arr, 0, n - 1, 9);
    // BSResult == -1 ? cout << "The Element is Not Present in This Array" << endl : cout << "The Element is Present At the Index--> " << BSResult << endl;

    int SPResult = StringPalindrome(str, n, 0);
    (SPResult == true) ? cout << "True" << endl : cout << "False" << endl;
}