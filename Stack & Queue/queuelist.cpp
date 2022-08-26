#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
class que
{
public:
    node *front;
    node *back;
    que()
    {
        front = NULL;
        back = NULL;
    }
    void push(int value)
    {
        node *n = new node(value);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        if (front > back)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        back->next = n;
        back = n;
    }
    void pop()
    {
        if (front == NULL || front > back)
        {
            cout << "Can't Pop" << endl;
            return;
        }
        node *del = front;
        front = front->next;
        delete del;
    }
    int peek()
    {
        if (front == NULL || front > back)
        {
            cout << "NO Element" << endl;
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL || front > back)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    que q;
    q.push(1);
    q.push(8);
    q.push(6);
    q.push(2);
    q.push(3);

    cout << "The Element in the Queue is " << q.peek() << endl;
    q.pop();
    cout << "The Element in the Queue is " << q.peek() << endl;
    q.pop();
    cout << "The Element in the Queue is " << q.peek() << endl;
    q.pop();
    cout << "The Element in the Queue is " << q.peek() << endl;
    q.pop();
    cout << "The Element in the Queue is " << q.peek() << endl;
    q.pop();
    
    cout << "Checks if the Queue is Empty or Not " << q.empty() << endl;
}