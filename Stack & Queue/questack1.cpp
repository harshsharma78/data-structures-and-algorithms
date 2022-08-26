// enqueue(push) costly
// Queue using Stack
#include <iostream>
#include <stack>
using namespace std;

class que
{
public:
    stack<int> s1;
    stack<int> s2;

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x); // Pushing the Elements considering the size of stack to be infinite
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop()
    {
        if (s1.empty())
        {
            cout << "Can't Pop" << endl;
            exit(0);
        }
        int top = s1.top();
        s1.pop();
        return top;
    }
    bool empty()
    {
        if (s1.empty())
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
    q.push(4);
    q.push(6);
    q.push(5);
    q.push(2);

    cout << "The Element in Queue is " << q.pop() << endl;
    cout << "The Element in Queue is " << q.pop() << endl;
    cout << "The Element in Queue is " << q.pop() << endl;
    cout << "The Element in Queue is " << q.pop() << endl;
    cout << "The Element in Queue is " << q.pop() << endl;
    cout << "Checks if the Queue is Empty or Not " << q.empty() << endl;
}