#include<algorithm>
#include<iostream>
using namespace std;
int gcd(int x,int y);
int main()
{
	int x,y,g;
	cout<<"Enter the two numbers\n";
	cin>>x>>y;
	g = gcd(x,y);
	cout<<"GCD of "<<x<<" and "<<y<<" is "<<g<<"\n";
	return 0;
}
int gcd(int x, int y)
{
	int rem = 0;
	rem = x%y;	
	if(rem==0)
		return y;	
	else
		return gcd(y,rem);
}
	
