#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,a,d,i,c=0;
	cout<<"Enter the value of n\n";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		a = i;
		while(a!=0)
		{
			d = a%10;
			if(d==3)
				break;			
			a = (int)a/10;
		}
		if(d!=3)
			c++;
	}
	cout<<"\nThe count of numbers that don't have a digit 3 = "<<c<<"\n";
	return 0;
}  

/*Output:

Enter the value of n
30

The count of numbers that don't have a digit 3 = 26
*/


