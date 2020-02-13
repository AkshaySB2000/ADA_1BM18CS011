#include<algorithm>
#include<iostream>
using namespace std;
int fact(int n);
int main()
{
	int n;
	cout<<"Enter the value of n\n";
	cin>>n;
	cout<<"The factorial of "<<n<<" i.e, "<<n<<"! = "<<fact(n)<<"\n";
	return 0;
}
int fact(int n)
{
	if(n==0)
		return 1;
	else 
		return (n*fact(n-1));
}
