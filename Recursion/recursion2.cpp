#include <iostream >
#include <cstring>
using namespace std;

string numpad[] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void keypad(string s, string result)
{
    if (s.length() == 0)
    {
        cout << result << endl;
        return;
    }
    char ch = s[0];
    string rest = s.substr(1);
    string arr = numpad[ch - '0']; //( ch - '0') <---- To get the index, we subtract the value from ASCII or
                                   //to get the corresponding value of the digit
    for (int i = 0; i < arr.length(); i++)
    {
        keypad(rest, result + arr[i]);
    }
}

void reversestr(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    char ch = s[0];
    string restof = (s.substr(1));
    reversestr(restof);
    cout << s[0];
}

void towerofhanoi(int n, string source, string dest, string help)
{
    if (n == 0)
    {
        return;
    }
    towerofhanoi(n - 1, source, help, dest);
    cout << "Moving element " << n << " from " << source << " to " << dest << endl;
    towerofhanoi(n - 1, help, dest, source);
}

string moveXtoend(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string restof = moveXtoend(s.substr(1));

    if (ch == 'x' || ch == 'X')
    {
        return (restof + ch);
    }
    return (ch + restof);
}

void sets(string s, string result)
{
    if (s.length() == 0)
    {
        cout << result << endl;
        return;
    }
    char ch = s[0];
    string restof = s.substr(1);
    sets(restof, result);
    sets(restof, result + ch);
}

void sets2(string s, string result)
{
    if (s.length() == 0)
    {
        cout << result << endl;
        return;
    }
    char ch = s[0];
    string restof = s.substr(1);
    int code = ch;
    sets2(restof, result);
    sets2(restof, result + ch);
    sets2(restof, result + to_string(code));
}

string removedup(string s) // Removes Duplicate Value that are in Sequence, not all the same value
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string restof = removedup(s.substr(1));
    if (ch == restof[0])
    {
        return restof;
    }
    return ch + restof;
}

void replacepi(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    char ch = s[0];
    string restof = s.substr(1);
    if ((s[0] == 'p' || s[0] == 'P') && (s[1] == 'i' || s[1] == 'I'))
    {
        cout << 3.14;
        replacepi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacepi(s.substr(1));
    }
}

int main()
{
    // reversestr("om");
    // towerofhanoi(4, "A", "C", "B");
    // cout << moveXtoend("XXxagswywzzxx");
    // sets("ABC", "");
    // cout << removedup("hghhhhhhdghdghhhghdghj");
    // replacepi("pidfhgdpiPIdebhsdh");
    // sets2("AB", "");
    keypad("35", "");
}