#include <iostream>
using namespace std;
class que
{
    int *arr;
    int front;
    int back;
    int n = 5;

public:
    que()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "Que Overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;

        if (front == -1)
        {
            front++;
        }
    }
    int pop()
    {
        if (front == -1 || front > back)
        {
            cout << "No Elements" << endl;
            return 0;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No Elements" << endl;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
    bool full(){
          if (back == n - 1)
        {
            cout << "Que Overflow" << endl;
            return true;
        }
        return false;
    }
};
int main()
{
    que q;
    cout << "Pushing Elements in a Queue" << endl;
    q.push(1);
    q.push(9);
    q.push(8);
    q.push(3);
    q.push(5);

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
    cout << "Checks if the Queue is Full or Not " << q.empty() << endl;
}