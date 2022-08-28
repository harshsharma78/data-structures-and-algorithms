// Count inversion---> arr[1,5,3,4]-----> Inversions--> ( 5,1) ( 5,3 ) (5,4) (4,1) (4,3 ).....
// if array is sorted in ascending then inversion count is 0 but max in descending
#include <iostream>
using namespace std;
int countinversion(int arr[], int n) // brute force method
{
    int inv = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                inv++;
        }
    }
    return inv;
}

int main()
{
    int size;
    cout << "Enter the Size of an Array" << endl;
    cin >> size;
    int arr[size];
    size = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter the Elements of an Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "The Total Number of Inversions are " << countinversion(arr, size) << endl;
}