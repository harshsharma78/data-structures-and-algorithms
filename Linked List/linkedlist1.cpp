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

void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *cycle;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
        {
            cycle = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = cycle;
}

bool detectcycle(node *&head)
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void removecycle(node *&head)
{
    node *fast = head;
    node *slow = head;
    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);
    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node *appendKnodes(node *&head, int k)
{
    node *newhead;
    node *newtail;
    node *tail = head;
    int l = length(head);
    int count = 1;

    while (tail->next != NULL)
    {
        if (k > l)
        {
            k = k % l;
        }
        if (count == l - k)
        {
            newtail = tail;
        }
        if (count == l - k + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
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
    // makecycle(head, 3);
    // display(head);

    // cout<<"After Removing Cycle"<<endl;
    // removecycle(head);
    // display(head);

    // cout << detectcycle(head);
    // cout << length(head);

    cout << "Appending K-nodes in the beginning of Linked List " << endl;
    node *newhead = appendKnodes(head, 7);
    display(newhead);

   
}