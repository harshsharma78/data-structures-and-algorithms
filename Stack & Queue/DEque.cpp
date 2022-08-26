#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_front(4);
    dq.push_front(2);
    dq.push_back(3);
    dq.push_back(5);
    for (auto i : dq)
    {
        cout << i << " ";
    }
}