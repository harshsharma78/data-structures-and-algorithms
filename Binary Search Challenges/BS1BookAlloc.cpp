#include <bits/stdc++.h>
using namespace std;
bool solve(int arr[], int n, int mid, int m)
{
    int sum = 0;
    int stu = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        if ((sum + arr[i]) > mid) // pages are not being distributed among allocated students then increase the no.
        {
            stu++;
            sum = arr[i];
            if (stu > m)
                return false;
        }
        else
            sum += arr[i];
    }
    return true;
}
int findpages(int arr[], int n, int m) // n --->size of array and m --->number of students
{
    int lb = 0;
    int sum = 0;
    int ub;
    int mid;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // combine the pages
        ub = sum;
        while (lb <= ub)
        {
            mid = (lb + ub) / 2;
            if (solve(arr, n, mid, m))
            {
                ans = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {12, 34, 67, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int m = 2;
    cout << "Minimum Number of Pages Allocated Among the Students are " << findpages(arr, size, m) << endl;
}