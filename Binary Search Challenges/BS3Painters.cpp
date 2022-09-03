// Painter's Partition
#include <bits/stdc++.h>
using namespace std;
int isfeasible(int boards[], int n, int mid)
{
    int sum = 0;
    int painters = 1;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
        if (sum > mid)
        {
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}
int Painters(int boards[], int n, int m) // m--->no. of painters
{
    int totalL = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = max(temp, boards[i]);
        totalL += boards[i];
    }
    int low = temp;
    int high = totalL;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int painters = isfeasible(boards, n, mid);
        if (painters <= m)
        {
            high = mid;
        }
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    int boards[] = {10, 20, 30, 40};
    int size = sizeof(boards) / sizeof(boards[0]);
    int painters = 2;
    cout << "The Minimum Time taken to Paint Boards is " << Painters(boards, size, painters) << endl;
}