#include<iostream>
using namespace std;


int hcf(int a,int b)
{
	if(a==b){
	
	return a;
	}
	else if(a>b)
	{
		return hcf(a-b,b);
	}
	else 
	return hcf(a,b-a);
}

int main() {
	int a,b;
    cout<<"enter the value of a,b : ";
    cin>>a>>b;
    cout<<hcf(a,b);
    return 0;
}
