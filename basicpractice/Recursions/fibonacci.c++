#include<iostream>
using namespace std;
//fibonacci series;
int fibo(int n)
{
	if(n==0||n==1)
	return n;
	else{
		return fibo(n-1)+fibo(n-2);
	}
}void printFibonacci(int n, int count = 0) {
    if(count < n) {
        cout << fibo(count) << " ";
        printFibonacci(n, count + 1);
    }
}
int main()
{
int no;
cout<<"enter the no of the fibo ";
cin>>no;
cout<<fibo(no)<<endl;
cout<<"the fibonacci series : ";
printFibonacci(no);
}