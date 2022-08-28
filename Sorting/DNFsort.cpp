// Dutch National Flag Sorting ---> DNF Sort
// 000  11111    -----     2222
// red  white   unknown    blue
#include <iostream>
using namespace std;
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}
void dnf(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(&arr[mid++], &arr[low++]);
        }

        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(&arr[mid], &arr[high--]);
        }
        else
        {
            return;
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {1, 0, 2, 1, 1, 0, 1, 2, 2, 1, 0, 0, 1, 0, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array Before Sorting"<<endl;
    print(arr, size);
    cout<<"Array After Sorting"<<endl;
    dnf(arr, size);
    print(arr, size);
}