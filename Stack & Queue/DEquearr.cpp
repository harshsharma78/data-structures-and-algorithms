#include <iostream>
using namespace std;
#define size 6
class DEque
{
public:
    int front, rear;
    int *arr;
    DEque()
    {
        front = rear = -1;
        arr = new int[size];
    }
    void enquefront(int value)
    {
        if ((front == 0 && rear == size - 1) || front == rear + 1)
        {
            cout << "Queue is Full" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[front] = value;
        }
        else if (front == 0)
        {
            front = size - 1;
            arr[front] = value;
        }
        else
        {
            front--;
            arr[front] = value;
        }
    }
    void enquerear(int value)
    {
        if ((front == 0 && rear == size - 1) || front == rear + 1)
        {
            cout << "Queue is Full" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = value;
        }
        else if (rear == size - 1)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
    }

    void dequefront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else if (front == rear)
        {
            cout << "The Dequed Element is " << arr[front] << endl;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            cout << "The Dequed Element is " << arr[front] << endl;
            front = 0;
        }
        else
        {
            cout << "The Dequed Element is " << arr[front] << endl;
            front++;
        }
    }
    void dequerear()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else if (front == rear)
        {
            cout << "The Dequed Element is " << arr[rear] << endl;
            front = rear = -1;
        }
        else if (rear == 0)
        {
            cout << "The Dequed Element is " << arr[rear] << endl;
            rear = size - 1;
        }
        else
        {
            cout << "The Dequed Element is " << arr[rear] << endl;
            rear--;
        }
    }

    int getfront()
    {
        return arr[front];
    }
    int getrear()
    {
        return arr[rear];
    }
    void display()
    {
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};
int main()
{
    DEque deq;
    cout << "Pushing Elements in DE-queue" << endl;
    deq.enquefront(1);
    deq.enquefront(2);
    deq.enquerear(3);
    deq.enquerear(5);
    deq.display();
    deq.dequefront();
    cout << "The Front Element of DE-queue is " << deq.getfront() << endl;
    cout << "The Rear Element of DE-queue is " << deq.getrear() << endl;
}