#include <iostream>
using namespace std;

int unique(int arr[], int size)
{
    int xorsum = 0;
    for (int i = 0; i < size; i++)
    {
        xorsum ^= arr[i];
    }
    return xorsum;
}
int main()
{
    int arr[] = {1, 2, 1, 2, 12};
    cout << unique(arr, 5) << endl;
}