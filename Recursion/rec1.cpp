#include <iostream>
#include <vector>
using namespace std;

// Possible Subsets of a Set
void subsets(int arr[], vector<int> &temp, int n, int index)
{
    if (index == n)
    {
        for (auto i : temp)
            cout << i << " ";
        cout << endl;
        return;
    }
    temp.push_back(arr[index]);
    subsets(arr, temp, n, index + 1);

    temp.pop_back();

    subsets(arr, temp, n, index + 1);
}

// Print Sets which are having Sum = k
void sumequals(int arr[], vector<int> &temp, int sum, int n, int index, int k)
{
    if (index == n)
    {
        if ((temp.size() != 0) && sum % k == 0)
        {
            for (auto i : temp)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    temp.push_back(arr[index]);
    sum = sum + arr[index];
    sumequals(arr, temp, sum, n, index + 1, k);

    temp.pop_back();
    sum -= arr[index];
    sumequals(arr, temp, sum, n, index + 1, k);
}

// Count the Sets which are having Sum = k
int sumequalscount(int arr[], vector<int> &temp, int sum, int n, int index, int k)
{
    if (index == n)
    {
        if ((temp.size() != 0) && sum % k == 0)
            return 1;
        else
            return 0;
    }
    temp.push_back(arr[index]);
    sum = sum + arr[index];
    int left = sumequalscount(arr, temp, sum, n, index + 1, k);

    temp.pop_back();
    sum -= arr[index];
    int right = sumequalscount(arr, temp, sum, n, index + 1, k);
    return (left + right);
}

// Print the Sets which are having Sum = S but the Repetition of same number is allowed i.e if S = 3 then {1,1,1}
int sumrepcount(int arr[], int sum, int n, int index)
{
    if (index == n)
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }
    int left = 0;
    int right = 0;
    if (arr[index] <= sum)
    {
        sum -= arr[index];
        left = sumrepcount(arr, sum, n, index);
        sum += arr[index];
    }
    right = sumrepcount(arr, sum, n, index + 1);
    return (left + right);
}

int main()
{
    int arr[] = {1, 2, 3};
    int add[] = {5, 4, 6};
    int count[] = {1, 2, 3}; // for sum = 4 ---> 1111,112,22,13 ; for sum = 6 --->111111,222,33,123,11112,1113,1122
    vector<int> temp;
    int k = 5;
    int n = 3;

    // subsets(arr, temp, n, 0);
    // sumequals(add, temp, 0, n, 0, k);
    cout << "The Count of Sets having Repetitions Allowed--> " << sumrepcount(count, 6, n, 0) << endl;

    // cout << sumequalscount(add, temp, 0, n, 0, k);

    return 0;
}
