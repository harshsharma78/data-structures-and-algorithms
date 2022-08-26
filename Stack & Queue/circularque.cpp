#include <iostream>
using namespace std;

int cq[5];
int front = 0, rear = 0, size = 5;
// front and rear/back=0 otherwise it will never
// reaches to start and keeps on overwriting the existing values [inshort infinite loop]
// always remember to enque values only less than size-1 i.e. 4 in this case bcz one space is occupied by 0

bool isfull()
{
    if ((rear + 1) % size == front)
    {
        // cout << "Queue Overflow" << endl;
        return true;
    }
    return false;
}
bool isempty()
{
    if (front == rear)
    {
        // cout << "Queue Underflow" << endl;

        return true;
    }
    return false;
}
void enque(int value)
{
    if (isfull())
    {
        cout << "Queue is Full" << endl;
    }
    rear = (rear + 1) % size; // formula for circular increment
    cq[rear] = value;
    cout << "Enqueued Element is " << value << endl;
}
int deque()
{
    int del = -1;
    if (isempty())
    {
        cout << "Queue is Empty" << endl;
    }
    front = (front + 1) % size;
    del = cq[front];
    return del;
}

int main()
{
    enque(1);
    enque(2);
    enque(5);
    enque(3);

    cout << "Dequed Element from Circular Queue is " << deque() << endl;
    cout << "Dequed Element from Circular Queue is " << deque() << endl;
    cout << "Dequed Element from Circular Queue is " << deque() << endl;
    cout << "Dequed Element from Circular Queue is " << deque() << endl;
    enque(11);
    enque(21);
    enque(51);
    enque(3);

    if (isempty())
    {
        cout << "Queue is Empty" << endl;
    }
    else if (isfull())
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
}