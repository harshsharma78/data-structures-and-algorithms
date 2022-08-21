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
bool search(node *head, int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

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

void insertion(node *&head, int value)
{
    node *n = new node(value);
    while (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertathead(node *&head, int value)
{
    node *n = new node(value);
    n->next = head;
    head = n;
}

void deletion(node *&head, int value)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        node *ptr = head;
        head = head->next;
        delete ptr;
    }
    node *temp = head;
    while (temp->next->data != value)
    {
        temp = temp->next;
    }
    node *del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

void deletionathead(node *&head)
{
    node *ptr = head;
    head = head->next;
    delete ptr;
}

node *reverse(node *&head)
{                         // NULL   0       ->    1   ->      2   ->        3  -> NULL
    node *prevptr = NULL; // pre    curr        next
    node *currptr = head;
    node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr; // Because this is the new head
}
node *reverserecursive(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newhead = reverserecursive(head->next);
    head->next->next = head; // to reverse (1->2)<---this link
    head->next = NULL;
    return newhead;
}

node *reverseknode(node *&head, int knode)
{                         // NULL   0       ->    1   ->      2   ->        3  -> NULL
    node *prevptr = NULL; // pre    curr        next
    node *currptr = head;
    node *nextptr;
    int count = 0;
    while (currptr != NULL && count < knode)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reverseknode(nextptr, knode);
    }
    return prevptr;
}
int main()
{
    node *head = NULL;
    cout << "Inserting Elements in a Linked List" << endl;
    insertion(head, 1);
    insertion(head, 2);
    insertion(head, 3);
    insertion(head, 4);
    display(head);

    // cout << "Inserting Elements in a Linked List at the Head" << endl;
    // insertathead(head, 2);
    // display(head);

    // cout << "Linear Search Output " << search(head, 2) << endl;
    // cout << "Deleting Elements in a Linked List at the Head" << endl;
    // deletionathead(head);
    // display(head);

    // cout << "Deleting Elements in a Linked List" << endl;
    // deletion(head, 4);
    // display(head);

    // cout << "Reversing Elements in a Linked List" << endl;
    // // node *newhead = reverse(head);
    // // display(newhead);
    // node *recurse = reverserecursive(head);
    // display(recurse);

    cout << "Reversing K-Node Elements in a Linked List" << endl;
    node *reversek = reverseknode(head, 2);
    display(reversek);
}