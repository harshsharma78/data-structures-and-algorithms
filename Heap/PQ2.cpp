#include <bits/stdc++.h>
using namespace std;

void K_Sorted_array(int arr[], int n, int k)
{
    priority_queue<int> pq;
    int start = 0;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        arr[start] = pq.top();
        pq.pop();
        start++;
        pq.push(arr[i]);
    }

    while (!pq.empty())
    {
        arr[start] = pq.top();
        pq.pop();
        start++;
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void K_Smallest_Element(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    cout << "The K-Smallest Elements in an Array are --> ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main()
{
    int arr_1[] = {10, 12, 15, 6, 9};
    size_t size_K_Sorted = sizeof(arr_1) / sizeof(arr_1[0]);

    cout << "Array Before K-Sorting --> ";
    print(arr_1, size_K_Sorted);

    cout << "Array After K-Sorting --> ";
    K_Sorted_array(arr_1, size_K_Sorted, 3);
    print(arr_1, size_K_Sorted);

    int arr_2[] = {8, 5, 12, 10, 0, 1, 6, 9};
    size_t size_K_Smallest = sizeof(arr_2) / sizeof(arr_2[0]);
    K_Smallest_Element(arr_2, size_K_Smallest, 4);
}