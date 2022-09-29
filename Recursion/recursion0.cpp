#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}

void dec(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " " << endl;
    dec(n - 1);
}

void inc(int n)
{
    if (n == 0)
    {
        return;
    }
    inc(n - 1);
    cout << n << " ";
}

int fibb(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibb(n - 1) + fibb(n - 2);
}

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int power(int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    return n * (power(n, (x - 1)));
}

int main()
{
    int n, p, i = 0;
    cout << "Enter the Value" << endl;
    cin >> n;
    //cin >> p; 
    //cout<<"Sum of n numbers is "<<sum(n)<<endl;
    // cout << "Fibbonacci of n numbers is " << endl;
    // while (i < n)
    // {
    //     cout << fibb(i) << endl;
    //     i++;
    // }
    // dec(n);
    // inc(n);

    //cout << "Factorial of " << n << " is " << fact(n) << endl;
    //cout << "Power of " << n << " raise to the power " << p << " is " << power(n, p) << endl;
}