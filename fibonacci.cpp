#include<algorithm>
#include<iostream>
#include<stdlib.h>
using namespace std;
int fib(int n);
int main()
{
	int n,f;
	cout<<"Enter n\n";
	cin>>n;
	f = fib(n);
	cout<<"The "<<n<<"th fibonacci number is "<<f<<"\n";
	return 0;
}
int fib(int n)
{
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else if(n<0)
	{
		cout<<"\nInvalid Input\n";
		exit(0);
	}
	else
		return (fib(n-1)+fib(n-2));
}
