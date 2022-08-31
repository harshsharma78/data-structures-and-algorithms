// Last Stone Weight
#include <bits/stdc++.h>
using namespace std;

int LastStoneWeight(vector<int> &stones)
{
    priority_queue<int> max_heap;
    int n = stones.size();
    for (int i = 0; i < n; i++)
        max_heap.push(stones[i]);

    int first, second;
    while (n > 0)
    {
        first = max_heap.top();
        max_heap.pop();

        second = max_heap.top();
        max_heap.pop();

        n -= 2;
        // if (first != second)
        if ((first - second) > 0)
        {
            n++;
            max_heap.push((first - second));
        }
    }
    if (!max_heap.empty())
        return max_heap.top();
    return 0;
}
int main()
{
    vector<int> arr = {2, 7, 50, 1, 8, 1};
    cout << "The Weight Of The Last Stone Left is " << LastStoneWeight(arr) << endl;
}