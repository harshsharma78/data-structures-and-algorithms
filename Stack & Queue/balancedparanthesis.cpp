#include <iostream>
#include <stack>
using namespace std;
bool balncdbrkts(string s)
{
    bool ans = true;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' or s[i] == '[' or s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')

                st.pop();
        }
        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')

                st.pop();
        }
        else if (s[i] == '}')
        {
            if (!st.empty() and st.top() == '{')

                st.pop();
        }
        else
        {
            ans = false;
            break;
        }
    }
    while (!st.empty())
    {
        return ans = false;
    }
    return ans;
}
int main()
{
    string s = "{[()]}";
    if (balncdbrkts(s))
        cout << "Valid" << endl;
    else
    {
        cout << "Not Valid" << endl;
    }
}
