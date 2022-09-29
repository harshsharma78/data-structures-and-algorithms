#include <iostream>
using namespace std;

void permutation(string s, string result)
{
    if (s.length() == 0)
    {
        cout << result << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i]; // denotes fixed string
        string rest = s.substr(0, i) + s.substr(i + 1);
        permutation(rest, result + ch);
    }
}

int tilingways(int n) // no. of ways to fill tiles vertically and horizontally
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return tilingways(n - 1) + tilingways(n - 2);
}

int maze(int n, int i, int j) // count no. of paths to reach end
{
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (i >= n || j >= n)
    {
        return 0;
    }
    return maze(n, i + 1, j) + maze(n, i, j + 1);
}

int countpaths(int start, int end)
{
    if (start == end)
    {
        return 1;
    }
    if (start > end)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countpaths(start + i, end);
    }
    return count;
}

int friendspairing(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    return friendspairing(n - 1) + friendspairing(n - 2) * (n - 1);
}

int knapsack(int value[], int weight[], int n, int W) // W-->Capacity
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (weight[n - 1] > W)
    {
        return knapsack(value, weight, n - 1, W);
    }
    return max(knapsack(value, weight, n - 1, W - weight[n]) + value[n - 1], knapsack(value, weight, n - 1, W));
}

int main()
{
    int value[]={10,2,3};
    int weight[]={10,30,40};
    // permutation("ABC", "");
    // cout << tilingways(3);
    // cout << maze(2,0,0);
    // cout << countpaths(0, 4);
    // cout << friendspairing(3);
    cout<<knapsack(value,weight,3,60);
}