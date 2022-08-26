#include <iostream>
#include <stack>
using namespace std;
int prece(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' or c == '*')
    {
        return 2;
    }
    else if (c == '+' or c == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
string infixtopostfix(string s)
{
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            result += s[i];
        }
        else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if ((s[i] == ')' || s[i] == ']' || s[i] == '}'))
        {
            while ((!st.empty()) && (st.top() != '(' || st.top() != '[' || st.top() != '{'))
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while ((!st.empty()) && (prece(st.top()) > prece(s[i])))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);  // pushing scanned operator to stack
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string s = "{a+b}";
    cout << infixtopostfix(s) << endl;
}