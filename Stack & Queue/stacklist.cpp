#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *top;
    node *next;
};
void traverse(node *top)
{
    node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
bool empty(node *top)
{
    if (top == NULL)
        return true;
    return false;
}
void push(node *&top, int data)
{
    node *temp = new node();
    if (!temp)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    temp->data = data;
    temp->next = top;
    top = temp;
}
void pop(node *&top)
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    node *temp = top;
    top = top->next;

    delete temp;
}
int stacktop(node *top)
{
    if (top != NULL)
        return top->data;
    exit(0);
}
int stackbottom(node *top)
{
    if (top != NULL)
    {
        while (top->next != NULL)
        {
            top = top->next;
        }
        return top->data;
    }
}

int main()
{
    node *top = NULL;
    cout << "Pushing Elements in a Stack using Linked List" << endl;
    push(top, 1);
    push(top, 2);
    push(top, 3);
    push(top, 5);
    traverse(top);

    pop(top);

    traverse(top);
    cout << "The top of the stack is " << stacktop(top) << endl;
    cout << "The bottom of the stack is " << stackbottom(top) << endl;
    cout << "Checks if stack is empty or not " << empty(top) << endl;
}
