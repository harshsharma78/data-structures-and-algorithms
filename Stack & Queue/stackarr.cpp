#include <iostream>
using namespace std;
#define n 100
class stack
{
public:
    int *arr; // Dynamically created an array
    int top;

    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    bool empty()
    {
        if (top < 0)
        {
            return true;
        }
        return false;
    }
    int Top()
    {
        if (top < 0)
        {
            // cout << "No Data in the Stack" << endl;
            return -1;
        }
        return arr[top];
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    for (int i = st.top; i >= 0; i--)
    {
        cout << st.arr[i] << endl;
    }
    cout << "The Topmost Element in a Stack is " << st.Top() << endl;
    cout << "Shows the Empty and Full condition of a Stack" << st.empty() << endl;
}