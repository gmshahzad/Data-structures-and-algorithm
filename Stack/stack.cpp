 /*
Question 1: Write a C++ program to implement a stack using an array. The program should support the following 
operations:
• push: add an element to the top of the stack
• pop: remove the element at the top of the stack
• is_empty: check if the stack is empty*/



#include <iostream>
#include <string>
using namespace std;

#define s 20

class stack
{
    int top;

public:
    int a[s];

    stack()
    {
        top = -1;
    }

    bool push(int z);
    int pop();
    int peek();
    bool Empty();
};

bool stack::push(int z)
{
    if (top >= (s - 1))
    {
        cout << "Stack Overflow! ";
        return false;
    }

    else
    {
        a[++top] = z;
        cout << z << " pushed in Stack" << endl;
        return true;
    }
}

int stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow! ";
        return 0;
    }

    else
    {
        int x = a[top--];
        return x;
    }
}

int stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty " << endl;
        return 0;
    }

    else
    {
        int x = a[top];
        return x;
    }
}

bool stack::Empty()
{
	if (top < 0)
    {
        cout << "Stack is Empty! " << endl;
        return 0;
    }
    else {
    	cout<<"Stack is not Empty! ";
	}
    return (top < 0);
}

int main()
{
    stack x;
    x.push(1);
    x.push(2);
    x.push(3);
     x.pop();
     x.Empty();
     cout<<endl;
     x.push(3);
    cout << endl;
    cout << x.pop() << " popped out from Stack " << endl;
    cout << x.pop() << " popped out from Stack " << endl;

    cout << endl;
    cout << "Top element of Stack is: " << x.peek() << endl;
    cout << x.pop() << " popped out from Stack " << endl;

    cout << endl;
    cout << "Top element of Stack is: " << x.peek() << endl;
   x.Empty();
}
    
//    while (!x.Empty())
//    {
//        cout << x.peek() << " ";
//        x.pop();
//    }
//    cout << endl
//         << endl;
//
//    
//    if (x.Empty())
//    {
//        cout << "Stack is Empty ";
//    }
//
//    else
//    {
//        cout << x.peek() << " ";
//        x.pop();
//    }
//    return 0;
//}
//
