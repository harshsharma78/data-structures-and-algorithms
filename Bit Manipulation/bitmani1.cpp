#include <iostream>
using namespace std;
int getbit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}
int setbit(int n, int pos)
{
    return (n | (1 << pos));
}
int clearbit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (n & mask);
}
int updatebit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = (n & mask);
    return (n | (value << pos));
}
int main()
{
    // cout << getbit(2, 0) << endl;       0010
    //cout << setbit(2, 3) << endl;
    // cout << clearbit(2, 1) << endl;
    cout << updatebit(2, 0, 1) << endl;
}