// dequeue(pop) costly using function call stack
// Queue using Stack
#include <iostream>
#include <stack>
using namespace std;

class que
{
public:
    stack<int> s;

    void push(int x)
    {
        s.push(x);
    }
    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        int valof = s.top(); // Popping the Element and Storing it temporarily
        s.pop();

        if (s.empty()) // Returning the Element which is there when count=1 i.e. 1--->4--->6--->5--->2
        {
            return valof;
        }
        int val = pop(); // Recursive Call

        s.push(valof); // Pushing back those Elements and repeating the steps

        return val;
    }
    bool empty()
    {
        if (s.empty())
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