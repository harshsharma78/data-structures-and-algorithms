#include <bits/stdc++.h>
using namespace std;

// Insert in a Heap ----> Up-Heapify
// Removal in a Heap ----> Down-Heapify

// Class MaxPQ ----> Line 86
// Inplace Heapsort ----> Line 169

class MinPQ
{
    vector<int> pq;

public:
    MinPQ()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getmin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    int getsize()
    {
        return pq.size();
    }
    void insert(int element)
    {
        pq.push_back(element);
        int Child_Index = pq.size() - 1;
        while (Child_Index > 0)
        {
            int Parent_Index = (Child_Index - 1) / 2;
            if (pq[Child_Index] < pq[Parent_Index])
            {
                swap(pq[Child_Index], pq[Parent_Index]);
                Child_Index = Parent_Index;
            }
            else
                break;
        }
    }
    int remove_min()
    {
        if (isEmpty())
            return 0;

        int result = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();

        int Parent_Index = 0;

        while (true)
        {
            int Left_Child = (2 * Parent_Index) + 1;
            int Right_Child = (2 * Parent_Index) + 2;
            int Min_Index = Parent_Index;

            if (Left_Child < pq.size() and pq[Left_Child] < pq[Min_Index]) // left child index should be a valid index
                Min_Index = Left_Child;

            if (Right_Child < pq.size() and pq[Right_Child] < pq[Min_Index]) // right child index should be a valid index
                Min_Index = Right_Child;

            if (Parent_Index == Min_Index)
                break;

            swap(pq[Parent_Index], pq[Min_Index]);
            Parent_Index = Min_Index;
        }
        return result;
    }

    void print()
    {
        for (int i = 0; i < pq.size(); i++)
        {
            cout << pq[i] << " ";
        }
        cout << endl;
    }
};

class MaxPQ
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getmax()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    int getsize()
    {
        return pq.size();
    }
    void print()
    {
        for (int i = 0; i < pq.size(); i++)
        {
            cout << pq[i] << " ";
        }
        cout << endl;
    }
    void insert(int element)
    {
        pq.push_back(element);
        int Child_Index = pq.size() - 1;
        while (Child_Index > 0)
        {
            int Parent_Index = (Child_Index - 1) / 2;
            if (pq[Child_Index] > pq[Parent_Index])
            {
                swap(pq[Child_Index], pq[Parent_Index]);
                Child_Index = Parent_Index;
            }
            else
                break;
        }
    }
    int remove_max()
    {
        if (isEmpty())
            return 0;

        int result = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();

        int Parent_Index = 0;

        while (true)
        {
            int Left_Child = (2 * Parent_Index) + 1;
            int Right_Child = (2 * Parent_Index) + 2;
            int Max_Index = Parent_Index;

            if (Left_Child < pq.size() and pq[Left_Child] > pq[Max_Index]) // left child index should be a valid index
                Max_Index = Left_Child;

            if (Right_Child < pq.size() and pq[Right_Child] > pq[Max_Index]) // right child index should be a valid index
                Max_Index = Right_Child;

            if (Parent_Index == Max_Index)
            {
                break;
            }

            swap(pq[Max_Index], pq[Parent_Index]);
            Parent_Index = Max_Index;
        }
        return result;
    }
};

void Min_Inplace_Heapsort(int pq[], int n)
// Array ---> 1 | 3  4  5  6  7  77
//                ci
{
    for (int i = 1; i < n; i++) // Build the Heap in Input Array
    {
        int Child_Index = i;
        while (Child_Index > 0)
        {
            int Parent_Index = (Child_Index - 1) / 2;
            if (pq[Child_Index] < pq[Parent_Index])
            {
                swap(pq[Child_Index], pq[Parent_Index]);
                Child_Index = Parent_Index;
            }
            else
                break;
        }
    }

    // Remove Min Element from Heap
    int size = n;
    while (size >= 1)
    {
        swap(pq[0], pq[size - 1]);
        size--; // Element ASSUMED to be removed

        // Down Heapify
        int Parent_Index = 0;

        while (true)
        {
            int left_child = 2 * Parent_Index + 1;
            int right_child = 2 * Parent_Index + 2;
            int min_index = Parent_Index;

            if (left_child < size and pq[left_child] < pq[min_index])
                min_index = left_child;

            if (right_child < size and pq[right_child] < pq[min_index])
                min_index = right_child;

            if (Parent_Index == min_index)
                break;

            swap(pq[Parent_Index], pq[min_index]);
            Parent_Index = min_index;
        }
    }
}
void Max_Inplace_Heapsort(int pq[], int n)
// Array ---> 1 | 3  4  5  6  7  77
//                ci
{
    for (int i = 1; i < n; i++) // Build the Heap in Input Array
    {
        int Child_Index = i;
        while (Child_Index > 0)
        {
            int Parent_Index = (Child_Index - 1) / 2;
            if (pq[Child_Index] > pq[Parent_Index])
            {
                swap(pq[Child_Index], pq[Parent_Index]);
                Child_Index = Parent_Index;
            }
            else
                break;
        }
    }

    // Remove Min Element from Heap
    int size = n;
    while (size >= 1)
    {
        swap(pq[0], pq[size - 1]);
        size--; // Element ASSUMED to be removed

        // Down Heapify
        int Parent_Index = 0;

        while (true)
        {
            int left_child = 2 * Parent_Index + 1;
            int right_child = 2 * Parent_Index + 2;
            int min_index = Parent_Index;

            if (left_child < size and pq[left_child] > pq[min_index])
                min_index = left_child;

            if (right_child < size and pq[right_child] > pq[min_index])
                min_index = right_child;

            if (Parent_Index == min_index)
                break;

            swap(pq[Parent_Index], pq[min_index]);
            Parent_Index = min_index;
        }
    }
}

int main()
{
    MinPQ Min;
    Min.insert(20);
    Min.insert(12);
    Min.insert(22);
    Min.insert(81);
    Min.insert(4);
    Min.insert(0);

    cout << "Printing Min-Heap --> ";
    Min.print();
    cout << "The Size of the Heap is --> " << Min.getsize() << endl;
    cout << "Checking if the Heap is Empty or Not --> " << Min.isEmpty() << endl;

    cout << "Removing Minimum Element from Heap --> ";
    while (!Min.isEmpty())
        cout << Min.remove_min() << " ";
    cout << endl
         << endl;

    MaxPQ Max;
    Max.insert(20);
    Max.insert(12);
    Max.insert(22);
    Max.insert(81);
    Max.insert(4);
    Max.insert(0);

    cout << "Printing Max-Heap --> ";
    Max.print();
    cout << "The Size of the Heap is --> " << Max.getsize() << endl;
    cout << "Checking if the Heap is Empty or Not --> " << Max.isEmpty() << endl;

    cout << "Removing Maximum Element from Heap --> ";
    while (!Max.isEmpty())
        cout << Max.remove_max() << " ";
    cout << endl
         << endl;

    int arr[] = {20, 12, 22, 81, 4, 0};
    Min_Inplace_Heapsort(arr, 6);
    cout << "Printing the Min Heapsort ---> "; // Always be in descending order
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Printing the Max Heapsort ---> "; // Always be in ascending order
    Max_Inplace_Heapsort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}