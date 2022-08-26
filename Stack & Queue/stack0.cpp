#include <iostream>
#include <stack>
using namespace std;

void reversesentence(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
void insertatbottom(stack<int> &s, int el)
{
    if (s.empty())
    {
        s.push(el);  // pushing that stored element
        return;
    }
    int topele = s.top();
    s.pop();
    insertatbottom(s, el);
    s.push(topele); // pushing the reversed elements in a stack
}
void reversestack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top(); // storing top element of stack
    st.pop();
    reversestack(st);        // storing other elements which are at top one by one
    insertatbottom(st, ele); // insert those elements at bottom
}
int main()
{
    string s = "Hey, Hello World";
    // reversesentence(s);
    stack<int> stc;
    stc.push(1);
    stc.push(6);
    stc.push(3);
    stc.push(4);
    stc.push(2);
    reversestack(stc);
    while (!stc.empty())
    {
        cout << stc.top() << " ";
        stc.pop();
    }
}