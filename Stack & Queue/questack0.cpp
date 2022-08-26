// dequeue(pop) costly
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
        s1.push(x);
    }
    int pop()
    {
        if (s1.empty() && s2.empty())
        {
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    bool empty()
    {
        if (s1.empty() and s2.empty())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    que q;
    int i;
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