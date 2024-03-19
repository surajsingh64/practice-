#include<iostream>
using namespace std;

class stack
{
private:
    int* a;
    int size, top;

public:
    stack(int s)
    {
        size = s;
        a = new int[s];
        top = -1;
    }

    ~stack()
    {
        delete[] a;
    }

    void push(int x);
    void pop();
    void peek();
    bool isfull();
    bool isempty();
    void display();
};

bool stack::isfull()
{
    return (top == size - 1);
}

void stack::push(int x)
{
    if (isfull())
        cout << "the stack is fully filled : ";
    else
    {
        top++;
        a[top] = x;
        display();
    }
}

bool stack::isempty()
{
    return (top == -1);
}

void stack::display()
{
    if (isempty())
        cout << "the is empty : ";
    else
    {
        cout << "the elements in the stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
    }
}

void stack::pop()
{
    if (isempty())
        cout << "the stack is underflow condition ";
    else
    {
        top--;
        display();
    }
}

void stack::peek()
{
    if (isempty())
        cout << "the stack is underflow condition ";
    else
    {
        cout << "The top element of the stack is: " << a[top]<<endl;
    }
}

int main()
{
    stack obj(9);
    int choice, item;

    while (true) {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> item;
                obj.push(item);
                break;
            case 2:
                obj.pop();
                break;
            case 3:
                obj.peek();
                break;
            case 4:
                obj.display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
