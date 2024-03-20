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

class stack
{
public:
    node *top;
    stack()
    {
        top = 0;
    }
    void addtotop(int n);
	void count();
    void deletefromtop();
    void pop();
    void display();
 
   
};
void stack::addtotop(int x)
{
	node*p=new node(x);
	if(top==0)
	top=p;
	else {
		p->next=top;
		top=p;
		display();
	}
}
void stack::display()
{
	node*temp=top;
	
	if(top==0)
	cout<<"the list is null";
	else {
		cout<<"the element in the stack is : ";
		while(temp!=0){
			cout<<temp->value<<" ";
			temp=temp->next;	
		}		
	}
	cout<<endl;
}
void stack::pop()
{
	if(top==0)
	cout<<"the stack is in underflow condition";
	else
	{
		node *p=top;
		cout<<"pop element : "<<p->value<<endl;
		top=p->next;
		delete p;
	}
}
int main()
{
	stack obj;
	obj.addtotop(45);
	obj.addtotop(47);
	obj.pop();
	obj.display();
	
	}
