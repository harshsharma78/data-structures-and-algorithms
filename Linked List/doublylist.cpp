#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *pre;
    node *next;
    node(int value)
    {
        data = value;
        pre = NULL;
        next = NULL;
    }
};
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void insertathead(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    if (head != NULL)
    {
        head->pre = n;
    }
    head = n;
}

void insertion(node *&head, int value)
{
    if (head == NULL)
    {
        insertathead(head, value);
        return;
    }
    node *n = new node(value);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->pre = temp;
}

void deleteathead(node *&head)
{
    node *del = head;
    head = head->next;
    head->pre = NULL;
    delete del;
}

void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteathead(head);
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp->next != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != NULL)
    {
        temp->next->pre = temp->pre;
    }
    temp->pre->next = temp->next;
}
int main()
{
    node *head = NULL;
    cout << "Inserting Elements in a Linked List" << endl;
    insertion(head, 1);
    insertion(head, 4);
    insertion(head, 3);
    insertion(head, 7);
    insertion(head, 4);
    display(head);
    cout << "Deleting Elements in a Linked List" << endl;
    deletion(head, 1);
    display(head);
}