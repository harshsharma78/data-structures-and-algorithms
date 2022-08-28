#include <iostream>
using namespace std;
// find the minimum in an array and then place it on the correct index
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minval = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minval])
            {
                // minval = j;
                // for comparing the minimum value and storing and updating it with new minimum value}
                int temp = arr[j];
                arr[j] = arr[minval];
                arr[minval] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of an Array" << endl;
    cin >> n;
    int arr[n];

    cout << "Enter Elements of an Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // for (int i = 0; i <= n - 2; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[j] < arr[i]) //8 45 12 34 21 51
    //         {
    //             int temp = arr[j];
    //             arr[j] = arr[i];
    //             arr[i] = temp;
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << "Array Before Sorting" << endl;
    print(arr, n);
    cout << "Array After Sorting" << endl;
    selectionsort(arr, n);
    print(arr, n);
}
