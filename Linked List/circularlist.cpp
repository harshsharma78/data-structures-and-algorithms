#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
void display(node *&head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void insertathead(node *&head, int value)
{
    node *n = new node(value);
    node *temp = head;
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
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
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void deleteathead(node *&head)
{
    node *temp = head;
    node *del = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
    delete del;
}
void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteathead(head);
    }
    node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

int main()
{
    node *head = NULL;
    cout << "Inserting Elements in a Linked List" << endl;
    insertion(head, 1);
    insertion(head, 2);
    insertion(head, 3);
    insertion(head, 4);
    insertion(head, 5);
    display(head);
    cout << "Deleting Elements in a Linked List" << endl;
    deletion(head, 2);
    display(head);
}