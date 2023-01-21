#include <iostream>
#include <string>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class DLL
{

public:
    void InsertLast(node *&head, int x);
    void InsertFirst(node *&head, int x);
    void display(node *head);
    bool search(node *head, int num);
};

void DLL::InsertLast(node *&head, int x)
{
    node *n = new node();
    n->data = x;
    if (head == NULL)
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
    n->prev = temp;
}

void DLL::InsertFirst(node *&head, int x)
{
    node *n = new node();
    n->data = x;
    n->next = head;
    if (head != NULL)
        head->prev = n;
    head = n;
}

void DLL::display(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << temp->data << " <-> NULL" << endl;

    if (temp->prev != NULL)
        temp = temp->prev;
    while (temp->prev != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << temp->data << " <-> NULL" << endl;
}

bool DLL::search(node *head, int num)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

int main()
{
    DLL s;
    node *head = NULL;

  
    s.InsertLast(head, 31);
    s.InsertLast(head, 32);
    s.InsertLast(head, 33);

    cout << "Inserted at Tail____" << endl;
    s.display(head);
    cout << endl;
    s.InsertFirst(head, 34);
    cout << "Inserted at Head____" << endl;
    s.display(head);
    
    cout << endl;
    cout << s.search(head, 33) << endl;
    return 0;
}
