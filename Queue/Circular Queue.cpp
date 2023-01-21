#include <iostream>
#include <string>
using namespace std;

class Circular_Queue
{
protected:
private:
    int front;
    int rear;
    int arr[4];
    int ItemCount;

public:
    Circular_Queue()
    {
        ItemCount = 0;
        front = -1;
        rear = -1;

        for (int i = 0; i < 4; i++)
        {
            arr[i] = 0;
        }
    }

    bool Empty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    bool Full()
    {
        if ((rear + 1) % 4 == front)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void EnQueue(int val)
    {
        if (Full())
        {
            cout << "Queue full" << endl;
            return;
        }

        else if (Empty())
        {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }

        else
        {
            rear = (rear + 1) % 4;
            arr[rear] = val;
        }
        ItemCount++;
    }

    int DeQueue()
    {
        int x = 0;
        if (Empty())
        {
            cout << "Queue is Empty" << endl;
            return x;
        }

        else if (rear == front)
        {
            x = arr[rear];
            rear = -1;
            front = -1;
            ItemCount--;
            return x;
        }

        else
        {
            cout << "front value: " << front << endl;
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % 4;
            ItemCount--;
            return x;
        }
    }

    int count()
    {
        return (ItemCount);
    }

    void display()
    {
        cout << "\nAll values in the Queue are: ";
        for (int i = 0; i < 4; i++)
        {
            cout << arr[i] << "  ";
        }
    }
};

int main()
{
    Circular_Queue cq;
    int value;
    int option;

p:
    do
    {
        cout << "\n\t\tDate: " << __TIME__ << "\t\tTime: " << __DATE__ << endl
             << endl;
        cout << "\n\n1. Insert in Queue " << endl;
        cout << "2. Delete from Queue " << endl;
        cout << "3. Check Queue is Empty or not " << endl;
        cout << "4. Check Queue is Full or not " << endl;
        cout << "5. Check Count " << endl;
        cout << "6. Display Queue elements " << endl;
        cout << "7. Clear Screen " << endl;
        cout << "8. Exit " << endl;
        cout << "\nEnter your choice: ";

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "\nEnqueue Operation \nEnter a value to Enqueue in the Queue: ";
            cin >> value;
            cq.EnQueue(value);
            break;

        case 2:
            cout << "\nDequeue Operation \nDequeued Value: " << cq.DeQueue() << endl;
            break;

        case 3:
            if (cq.Empty())
            {
                cout << "Queue is Empty" << endl;
            }

            else
            {
                cout << "Queue is not Empty" << endl;
            }
            break;

        case 4:
            if (cq.Full())
            {
                cout << "Queue is Full" << endl;
            }

            else
            {
                cout << "Queue is not Full" << endl;
            }
            break;

        case 5:
            cout << "Count of items in Queue is: " << cq.count() << endl;
            break;

        case 6:
            cq.display();
            cout << endl;
            break;

        case 7:
            system("cls");
            break;

        case 8:
            exit(0);
            break;

        default:
            cout << "\nInvalid Input! " << endl;
            goto p;
        }

    } while (option != 8);

    return 0;
}