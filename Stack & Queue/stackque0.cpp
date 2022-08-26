// push costly
// Stack usin queue
#include <iostream>
#include <queue>
using namespace std;
class stack
{
public:
    queue<int> q1, q2;
    int Size;

    stack()
    {
        Size = 0;
    }
    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        q1.pop();
        Size--;
    }
    void push(int x)
    {
        Size++;
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> swap = q1;
        q1 = q2;
        q2 = swap;
    }
    int size()
    {
        return Size;
    }
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(5);
    st.push(2);
    st.push(4);
    st.push(3);

    cout << "The Top of Stack is " << st.top() << endl;
    st.pop();
    cout << "The Top of Stack is " << st.top() << endl;
    st.pop();
    cout << "The Top of Stack is " << st.top() << endl;
    st.pop();
    cout << "The Top of Stack is " << st.top() << endl;
    st.pop();
    cout << "The Top of Stack is " << st.top() << endl;
    st.pop();
}