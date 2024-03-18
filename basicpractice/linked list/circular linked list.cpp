#include <iostream>
using namespace std;

class node {
public:
    node* next;
    node* prev;
    int value;

    node(int d, node* n = 0, node* p = 0) {
        value = d;
        next = n;
        prev = p;
    }
};

class CLL {
public:
    node* tail;

    CLL() {
        tail = 0;
    }

    ~CLL() {
        if (tail != 0) {
            node* p = tail->next;
            do {
                node* temp = p;
                p = p->next;
                delete temp;
            } while (p != tail->next);
            tail = 0;
        }
    }

    void addtohead(int n);
    void addtotail(int n);
    void deletefromhead();
    void deletefromtail();
    void display();
    void reverse();
};

void CLL::addtohead(int x) {
    node* p = new node(x);
    if (tail == 0) {
        tail = p;
        tail->next = tail;
    } else {
        p->next = tail->next;
        tail->next = p;
    }
    
}

void CLL::addtotail(int x) {
    node* p = new node(x);
    if (tail == 0) {
        tail = p;
        tail->next = tail;
    } else {
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }
    
}

void CLL::display() {
    if (tail == 0)
        cout << "the list is empty";
    else {
        node* p = tail->next;
        do {
            cout << p->value << " ";
            p = p->next;
        } while (p != tail->next);
    }
}
void CLL::deletefromhead() {
    if (tail == 0) {
        cout << "the list is empty";
        return;
    }
    if (tail->next == tail) {
        delete tail;
        tail = 0;
    }
    else {
        node* temp = tail->next;
        tail->next = temp->next;
        temp->next->prev = tail;
        delete temp;
    }
    cout<<"after the deletion from head the list is : ";
	display();
}
void CLL::deletefromtail() {
    if (tail == 0)
        cout << "the list is empty";
    else if (tail->next == tail) {
        delete tail;
        tail = 0;
    } else {
        node* p = tail->next;
        while (p->next != tail) {
            p = p->next;
        }
        p->next = tail->next;
        delete tail;
        tail = p;
    }
    cout<<"after the deletion from tail the list is : ";
	display();
}

void CLL::reverse()
{
	tail=tail->next;
	node*p=tail->next;
	tail->next=tail;
	while(p!=tail)
	{
		addtohead(p->value);
		node*temp=p;
		p=p->next;
		delete temp;
	}


    cout << "After reversing the list, the new list is: ";
    display();
}


int main() {
    CLL obj;
    int choice;
    int value;
    
    while (true){
        cout << "\nCircular Linked List Operations Menu:\n";
        cout << "1. Add to Head\n";
        cout << "2. Add to Tail\n";
        cout << "3. Delete from Head\n";
        cout << "4. Delete from Tail\n";
        cout << "5. Display\n";
        cout << "6. Reverse\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to add to head: ";
                cin >> value;
                obj.addtohead(value);
                break;
            case 2:
                cout << "Enter value to add to tail: ";
                cin >> value;
                obj.addtotail(value);
                break;
            case 3:
                obj.deletefromhead();
                break;
            case 4:
                obj.deletefromtail();
                break;
            case 5:
                cout << "Circular Linked List: ";
                obj.display();
                break;
            case 6:
                obj.reverse();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } 

    return 0;
}
