#include <iostream>
using namespace std;
//void display()
// {
//     node *temp = front;
//     if (temp != rear)
//     {
//         while (temp != rear)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         temp = rear;
//     }
//     if (temp != front)
//     {

//         while (temp != front)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//     }
// }

struct node
{

    node *prev;
    node *next;
    int data;

    static node *nodes(int data)
    {
        // node *temp = new node(node);
        node *temp = (node *)malloc(sizeof(node));
        temp->prev = temp->next = NULL;
        temp->data = data;
        return temp;
    }
};
class DEque
{
public:
    node *front;
    node *rear;
    int Size;

    DEque()
    {
        front = rear = NULL;
        Size = 0;
    }

    void pushfront(int data)
    {
        node *temp = node::nodes(data);
        if (temp == NULL)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            if (front == NULL)
            {
                rear = front = temp;
            }
            else
            {
                {
                    temp->next = front;
                    front->prev = temp;
                    front = temp;
                }
            }
           // cout << front->data << " ";
            Size++;
        }
    }
    void pushrear(int data)
    {
        node *temp = node::nodes(data);
        if (temp == NULL)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            if (rear == NULL)
            {
                rear = front = temp;
            }
            else
            {
                {
                    temp->next = rear;
                    rear->prev = temp;
                    rear = temp;
                }
            }
            cout << rear->data << " ";
            Size++;
        }
    }
    void deletefront()
    {
        if (isempty())
        {
            cout << "Underflow" << endl;
        }
        node *del = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        else
        cout << endl<<"The Deleted Value is " << front->data << endl;
            front->prev = NULL;
        free(del);
        Size--;
    }
    void deleterear()
    {
        if (isempty())
        {
            cout << "Underflow" << endl;
        }
        node *del = rear;
        front = rear->next;
        if (rear == NULL)
        {
            front = NULL;
        }
        else
            rear->next = NULL;
        cout << "The Deleted Value is " << rear->data << endl;
        free(del);
        Size--;
    }

    int getrear()
    {
        if (isempty())
        {
            return -1;
        }
        return rear->data;
    }
    int getfront()
    {
        if (isempty())
        {
            return -1;
        }
        return front->data;
    }
    bool isempty()
    {
        return (front == NULL);
    }

    int size()
    {
        return Size;
    }
    void display()
    {
        node *temp = front;

     if (temp->data != rear->data)
       {
            while (temp != rear)
            {
                cout << temp->data << " ";
                temp = temp->next;
                cout << temp->data << " ";
            }
    }
    }
};

int main()
{

    DEque dq;
    dq.pushfront(4);
    dq.pushfront(2);
    dq.display();
    dq.pushrear(3);
    dq.pushrear(5);
    dq.deletefront();
    dq.deleterear();
    cout << endl
         << "The Front Element of DE-queue is " << dq.getfront() << endl;
    cout << "The Rear Element of DE-queue is " << dq.getrear() << endl;
    cout << "The Size of the Element of DE-queue is " << dq.size() << endl;
    //2435
}