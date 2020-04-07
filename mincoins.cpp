#include<algorithm>
#include<iostream>
void mincoins(int n);
using namespace std;
int main()
{
	int a;
	cout<<"Enter the amount for which change is to be found\n";
	cin>>a;
	if(a>0)
	{
		cout<<"\nFollowing are the coins exchanged for "<<a<<"\n";
		mincoins(a);
	}
	else
		cout<<"\nInvalid amount";
	cout<<endl;
	return 0;
}
void mincoins(int a)
{
	int deno[] = {1,2,5,10,20,50,100,200,500,2000};
	int n = (int)sizeof(deno)/sizeof(deno[0]);	
	int coins[30],i,c = 0;
	for(i=n-1;i>=0;i--)
	{
		while(a>=deno[i])
		{
			a -= deno[i];
			coins[c++] = deno[i];
		}
	}
	
	for(i=0;i<c;i++)
		cout<<coins[i]<<" ";
	cout<<"\n\nThe minimum number of coins are\n";
	cout<<c;
}

/*Output:

Enter the amount for which change is to be found
3566

Following are the coins exchanged for 3566
2000 500 500 500 50 10 5 1 

The minimum number of coins are
8
*/

