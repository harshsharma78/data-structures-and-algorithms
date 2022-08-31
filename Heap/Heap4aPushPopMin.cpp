#include <bits/stdc++.h>
using namespace std;

#define size 100
int arr[size];
int heapsize;

void HeapPush(int value)
{
    arr[heapsize] = value;
    int i = heapsize;
    if (heapsize > size)
        cout << "Heap Overflow" << endl;

    while (i > 0 and arr[(i - 1) / 2] > arr[i])
    {
        swap(arr[(i - 1) / 2], arr[i]);
        i = (i - 1) / 2;
    }
    heapsize += 1;
}
int HeapPop()
{
    if (heapsize < 0)
        cout << "Heap Underflow" << endl;

    int i = 0;
    int child;
    
    int popped = arr[0];
    arr[0] = arr[heapsize - 1];
    heapsize -= 1;

    while ((2 * i + 1) < heapsize) //  not reaches end or NULL or leaf node
    {
        if (!(2 * i + 2))
            child = (2 * i + 1);
        else
        {
            if (arr[2 * i + 1] < arr[2 * i + 2])
                child = (2 * i + 1);
            else
                child = (2 * i + 2);
        }
        if (arr[i] > arr[child])
        {
            swap(arr[i], arr[child]);
            i = child;
        }
        else
            break;
    }
    return popped;
}
void printarray()
{
    for (int i = 0; i < heapsize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Heap Elements Are:" << endl;
    HeapPush(15);
    HeapPush(23);
    HeapPush(11);
    HeapPush(13);
    HeapPush(19);
    printarray();

    cout << "Heap After Popping an Element" << endl;
    cout << "The Popped Element is: " << HeapPop() << endl;
    cout << "The Remaining Elements in Heap Are:" << endl;
    printarray();
}