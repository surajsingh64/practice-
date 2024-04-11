#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = 0;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = 0;
        rear = 0;
    }

    ~Queue() {
        while (front != 0) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = 0;
    }

    bool isEmpty() {
        return (front == 0 && rear == 0);
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
        } else {
            Node* temp = front;
            cout << "Deleted " << front->data << endl;
            if (front == rear) {
                front = rear = 0;
            } else {
                front = front->next;
            }
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            while (temp != 0) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int data;
    int choice;
  
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
