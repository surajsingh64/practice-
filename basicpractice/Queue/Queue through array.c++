#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int size, rear, front;

public:
    Queue(int s) {
        size = s;
        arr = new int[s];
        rear = front = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return (rear == size - 1);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int x) {
        if (isFull())
            cout << "Queue overflow" << endl;
        else if (isEmpty()) {
            front = rear = 0;
            arr[rear] = x;
        } else {
            rear++;
            arr[rear] = x;
        }
        display();
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "The queue is underflow" << endl;
        } else if (front == rear) {
            cout << "Deleted " << arr[front] << endl;
            front = rear = -1;
        } else {
            cout << "Deleted " << arr[front] << endl;
            front++;
        }
    }

    void display() {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    int choice, data, size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue q(size);

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}
