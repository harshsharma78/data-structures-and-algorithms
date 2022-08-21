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

void evenafterodd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenstart = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
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

void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    node *temp2 = head2;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
int intersection(node *&head1, node *&head2)
{
    node *p1;
    node *p2;
    int d = 0;
    int l1 = length(head1);
    int l2 = length(head2);
    if (l1 > l2)
    {
        d = l1 - l2;
        p1 = head1;
        p2 = head2;
    }
    if (l2 > l1)
    {
        d = l2 - l1;
        p1 = head2;
        p2 = head1;
    }
    while (d) // To reach the desired link
    {
        p1 = p1->next;
        if (p1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (p1 != NULL && p2 != NULL)
    {
        if (p1 == p2)
        {
            return p1->data;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}

node *mergelists(node *&head1, node *&head2)
{
    node *dummy = new node(-1);
    node *p1 = head1;
    node *p2 = head2;
    node *p3 = dummy;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}
node *mergelistsrecursive(node *&head1, node *&head2)
{
    node *result;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergelistsrecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergelistsrecursive(head1, head2->next);
    }
    return result;
}
int main()
{
    node *head = NULL;
    node *head1 = NULL;
    node *head2 = NULL;

    cout << "Inserting Elements in a Linked List" << endl;
    insertion(head, 1);
    insertion(head, 2);
    insertion(head, 3);
    insertion(head, 4);
    insertion(head, 5);

    insertion(head1, 1);
    insertion(head1, 2);
    insertion(head1, 3);
    insertion(head1, 4);
    insertion(head1, 5);

    insertion(head2, 7);
    insertion(head2, 8);
    insertion(head2, 9);

    // display(head);

    // cout << "Inserting Even Positioned Nodes After Odd Positioned Nodes in a Linked List" << endl;
    // evenafterodd(head);
    // display(head);

    // intersect(head1, head2, 3);
    // display(head1);
    // cout << "Linked List After Intersection" << endl;
    // display(head2);
    // cout << "Intersecting at position " << intersection(head1, head2) << endl;

    // cout << "Merging Two Sorted Linked Lists" << endl;
    // node *newhead = mergelists(head1, head2);
    // display(newhead);
    
    cout << "Merging Two Sorted Linked Lists Using Recursion" << endl;
    node *newheadrec = mergelistsrecursive(head1, head2);
    display(newheadrec);
}