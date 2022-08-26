#include <iostream>
#include <stack>
#include <algorithm>
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
string infixtoprefix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            result += s[i];
        }
        else if (s[i] == '(') // || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')') // || s[i] == ']' || s[i] == '}')
        {
            while (!st.empty() && st.top() != '(') // || st.top() != '[' || st.top() != '{')
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
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    string s = "(a+b)";
    cout << infixtoprefix(s) << endl;
}