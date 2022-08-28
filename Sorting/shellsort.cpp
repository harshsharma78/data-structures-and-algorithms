// also known as gap sort
#include <iostream>
using namespace std;
void swap(int *fst, int *sec)
{
    int temp = *fst;
    *fst = *sec;
    *sec = temp;
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void shellsort(int arr[], int n)
{
    int x = 4;
    int gap = x; // take any value and try to find the best complexity
    int i, j = gap;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (j = gap; j < n; j++)
        {
            for (i = j - gap; i >= 0; i -= gap)
            {
                if (arr[i + gap] < arr[i])
                {
                    swap(&arr[i + gap], &arr[i]);
                }
            }
        }
    }
}
int main()
{
    int arr[] = {12, 2, 132, 29, 1, 32, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array Before Sorting" << endl;
    display(arr, size);

    cout << "Array After Sorting" << endl;
    shellsort(arr, size);
    display(arr, size);
}