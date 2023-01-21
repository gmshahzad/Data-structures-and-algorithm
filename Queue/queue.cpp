#include <iostream>
#include <string>
using namespace std;

class Circular_Queue
{
private:
    int front;
    int rear;
    int arr[10];
    int ItemCount;

public:
    Circular_Queue()
    {
        ItemCount = 0;
        front = -1;
        rear = -1;

        for (int i = 0; i < 10; i++)
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
        if ((rear + 1) % 10 == front)
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
            rear = (rear + 1) % 10;
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
            front = (front + 1) % 10;
            ItemCount--;
            return x;
        }
    }

    void display()
    {
        cout << "\nAll values in the Queue are: ";
        for (int i = 0; i < 10; i++)
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

    do
    {
        cout << "\n\n1. Insert in Queue (EnQueue) " << endl;
        cout << "2. Delete from Queue (DeQueue) " << endl;
        cout << "3. Check Queue is Empty or not " << endl;
        cout << "4. Check Queue is Full or not " << endl;
        cout << "5. Display Queue elements " << endl;
        cout << "6. Exit " << endl;
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
            cq.display();
            cout << endl;
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 6);

    return 0;
}

