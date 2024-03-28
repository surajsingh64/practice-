#include<iostream>
using namespace std;
class node
{
public:
    node *next; // Storing address of node class object
    int value;
    node(int d, node *n = 0)
    {
        value = d;
        next = n;
    }
    // ~Node();
};

class SLL
{
public:
    node *head;
    SLL()
    {
        head = 0;
    }
    void addtohead(int n);
    void count();
    void deletefromhead();
    void insert(int index,int n);
    void Delete(int n);
    void display();
    void reverse();
   
};
void SLL::addtohead(int x)
{
	node*p=new node(x);
	if(head==0)
	head=p;
	else {
		p->next=head;
		head=p;
	}
}
void SLL::display()
{
	node*temp=head;
	
	if(head==0)
	cout<<"the list is null";
	else {
		
		while(temp!=0){
			cout<<temp->value<<" ";
			temp=temp->next;	
		}		
	}
	cout<<endl;
}

void SLL::deletefromhead()
{
	node*p=head;
	if(head==0)
	cout<<"the list is empty ";
	else{
		head=head->next;
		delete p;
	}
}
void SLL::insert(int index, int x) {
    if (index == 1)
        addtohead(x);
    else {
        node* in = new node(x);
        int count = 1;
        node* p = head;
        node* prev = nullptr;
        while (p != nullptr && count != index) {
            prev = p;
            p = p->next;
            count++;
        }
        if (count != index) {
            cout << "Invalid index" << endl;
            delete in;
            return;
        }
        // Insert node in between prev and p
        prev->next = in;
        in->next = p;
    }
}

void SLL::count()
{
if(head==0)
cout<<"the list is empty";
else
{
	int cnt=0;
	node*p=head;
	while(p!=0)
	{
		cnt++;
		cout<<p->value<<" ";
		p=p->next;
	}
	cout<<"the total element is "<<cnt;
}
}
void SLL::Delete(int x)
{
	node*p=head;
	node*prev=0;
	while (p!=0&&p->value!=x)
	{
		prev=p;
		p=p->next;
	}
	if(p==0){
	cout<<"element not found ";
	}
	else if(p==head)
	deletefromhead();
	else{
		prev->next=p->next;
		delete p;
	}
}
void SLL::reverse()
{
	node*p=head->next;
	head->next=0;
	while(p!=0)
	{
		addtohead(p->value);
		node*temp=p;
		p=p->next;
		delete temp;
	}
}
int main()
{ SLL obj;
    int choice;
    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Add to head\n";
        cout << "2. Delete from head\n";
        cout << "3. Insert\n";
        cout << "4. Delete\n";
        cout << "5. Display\n";
        cout << "6. Count\n";
        cout << "7. Reverse\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to add to head: ";
                cin >> value;
                obj.addtohead(value);
                cout<<endl;
                break;
            }
            case 2:
                obj.deletefromhead();
                cout<<endl;
                break;
            case 3: {
                int index, value;
                cout << "Enter index and value to insert: ";
                cin >> index >> value;
                obj.insert(index, value);
                cout<<endl;
                break;
            }
            case 4: {
                int value;
                cout << "Enter value to delete: ";
                cin >> value;
                obj.Delete(value);
                cout<<endl;
                break;
            }
            case 5:
                obj.display();
                cout<<endl;
                break;
            case 6:
                obj.count();
                cout<<endl;
                break;
            case 7:
                obj.reverse();
                cout<<endl;
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
	return 0;
}
