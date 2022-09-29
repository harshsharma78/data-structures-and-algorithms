#include <iostream>
using namespace std;

bool arrsort(int arr[], int size)
{
    if (size == 1)
    {
        return true;
    }
    bool restarr = arrsort(arr + 1, size - 1);
    return ((arr[0] < arr[1]) && restarr);
}

int firstoccurence(int arr[], int size, int index, int element)
{
    if (size == index)
    {
        return -1;
    }
    if (arr[index] == element)
    {
        return index;
    }
    return firstoccurence(arr, size, index + 1, element);
}
int lastocc(int arr[], int size, int index, int element)
{
    if (index == size)
    {
        return -1;
    }
    int restarr = lastocc(arr, size, index + 1, element);
    if (restarr != -1)
    {
        return restarr;
    }
    if (arr[index] == element)
    {
        return index;
    }
    return -1;
}
int main()
{
    int arr[] = {4, 2, 3, 6};
    //int size = sizeof(arr) / sizeof(arr[0]);
    // cout << arrsort(arr, size)<<endl;
    //cout << lastocc(arr, size, 0, 2) << endl;
    int x = 2;
    int size = 4;
    cout << firstoccurence(arr, size, 0, x) << endl;
}