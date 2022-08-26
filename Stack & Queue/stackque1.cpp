// pop costly
// Stack using que
#include <iostream>
#include <queue>
using namespace std;
class stack
{
    int Size;
    queue<int> q1, q2;

public:
    stack()
    {
        Size = 0;
    }
    void push(int x)
    {
        q1.push(x);
        Size++;
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "Can't Pop" << endl;
            return;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        Size--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int top()
    {
        if (q1.empty())
        {
            return 0;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front(); // Saving the top element
        q1.pop();
        q2.push(temp);

        queue<int> swap = q1;
        q1 = q2;
        q2 = swap;

        return temp;
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(8);
    st.push(9);
    st.push(2);
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