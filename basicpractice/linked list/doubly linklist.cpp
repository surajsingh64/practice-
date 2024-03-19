#include<iostream>
using namespace std;
class node
{
	public:
	node*next;
	node*prev;
	int value;
	node(int d,node*n=0,node*p=0){
	
	value=d; 
	next=n;
	prev=p;
}
};
class DLL
{
public:
    node *head;
    node*tail;
    DLL()
    {
        head = 0;
        tail =0;
    }
      ~ DLL(){
            node* temp=head;
            while(head!=0){
                head=head->next;
                delete temp;
                temp=head;
            }
            tail=0;
           }
             void addtohead(int n);
             void addtotail(int n);
             void insert(int index,int n);
             void deletefromhead();
             void deletefromtail();
             void Delete(int n);
             void display();
             void count();
             void reverse();
   
};
void DLL::addtohead(int x)
{
	node* p=new node(x);
	if (head==0)
		head=tail=p;
	else{
		p->next=head;
		head->prev=p;
		head=p;
		
	}
}
void DLL::display() {
  node* temp = head;
  if (head == 0) {
    cout << "The list is empty" << endl;
  } else {
    node* current = head; // Temporary pointer for traversal
    while (current != 0) {
      cout << current->value << " ";
      current = current->next;
    }
    cout << endl;
  }
}
void DLL::addtotail(int x)
{
	node*p=new node(x);
	if(head==0)
	head=tail=0;
	else
	{
		tail->next=p;
		p->prev=tail;
		tail=p;
	}
}
void DLL::count()
{
	node*temp=head;	
	if(head==0)
	cout<<"list is empty";
	else
	{	int count=1;
		while(temp!=tail)
		{	count++;
			temp=temp->next;
			
		}
		cout << "Number of nodes in the list: " << count << endl;
		
	}
}
void DLL:: insert(int index,int y){
    if(index==1){
        addtohead(y);
    }
   else{ 
     node* ind=new node(y);
     int count=1;
     node* P=head;
     node* previous=0;
     while(P!=0 && count!=index){
        previous=P;
        P=P->next;
       
        count++;
		}
    if(P!=0)
	{
    previous -> next=ind;
    ind -> next=P;
    ind -> prev=previous;
    P -> prev= ind;
    }
    else{
      addtotail(y);
     }
  
   }
   cout<<"after insertion at position  "<<index<<" the list is : ";
   display();
}
void DLL::deletefromhead()
{
	if(head==0)
	cout<<"the list is empty";
	else
	{
		node*p=head;
		head=head->next;
		if(head==0)
		tail=0;
		else
		{
			head->prev=0;
			delete p;
		}		
	}
	cout<<"after the deletion from head the list is : ";
	display();
}
void DLL::deletefromtail()
{
	if(head==0)
	cout<<"the list empty";
	else
	{
		node*p=tail;
		tail=tail->prev;
		if(tail==0)
		head=0;
		else
		{
			tail->next=0;
			delete p;
		}
	}
	cout<<"after the deletion from tail the list is : ";
	display();
}
void DLL ::Delete(int x){
 node*P=head;
 
 while(P!=0&&P->value!=x){
    P=P->next;
 }
 if(P==0){
    cout<<" element not found "<<endl;

 }
 else if (P==head){
    deletefromhead();
 }
 else if(P==tail){
    deletefromtail();
 }
 else{
    P->prev->next=P->next;
    P->next->prev=P->prev;
   
 }
  delete P;
  	cout<<"after the deletion a particular value from the list then new list is : ";
	display();
}
void DLL::reverse(){

    node *P = head->next;
    head->next=0;
    tail=head;
    while(P!=0){
        addtohead(P->value);
        node *temp=P;
        P=P->next;
        delete temp;
   }
   cout<<"after the reverse the list then new list is : ";
   display();     
    
};
int main()
{
    DLL obj;
    int choice;
    int value, index;

    while (true)
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Add to head\n";
        cout << "2. Add to tail\n";
        cout << "3. Insert\n";
        cout << "4. Delete from head\n";
        cout << "5. Delete from tail\n";
        cout << "6. Delete a particular value\n";
        cout << "7. Reverse the list\n";
        cout << "8. Display the list\n";
        cout << "9. Count nodes in the list\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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
            cout << "Enter index and value to insert: ";
            cin >> index >> value;
            obj.insert(index, value);
            break;
        case 4:
            obj.deletefromhead();
            break;
        case 5:
            obj.deletefromtail();
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> value;
            obj.Delete(value);
            break;
        case 7:
            obj.reverse();
            break;
        case 8:
            cout << "The list is: ";
            obj.display();
            break;
        case 9:
            obj.count();
            break;
        case 10:
            cout << "Exiting program.\n";
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
