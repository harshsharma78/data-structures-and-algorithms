#include <iostream>
using namespace std;

int numberofones(int n)
{
    int count = 0;
    while (n)
    {
        n = (n & (n - 1));
        count++;
    }
    return count;
}

bool ispowerof2(int n)
{
    return (n && !(n & (n - 1)));
}

void subsets(int arr[], int size)
{
    for (int i = 0; i < (1 << size); i++)
    { // Must Remember -----> (1<<n)=2^n and (1>>n)=2/n
        for (int j = 0; j < size; j++)
        {
            if (i & (i << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int arr[4] = {1, 2, 3};
    // cout << numberofones(3) << endl;
    //cout << ispowerof2(0) << endl;
    subsets(arr, 3);
}