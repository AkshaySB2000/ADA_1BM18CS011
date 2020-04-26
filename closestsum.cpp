#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a[20],b[20],n1,n2,i,j,x,num1,num2,min=1000,msum;
	cout<<"Enter lengths of two arrays\n";
	cin>>n1>>n2;
	cout<<"Enter elements of first array\n";
	for(i=0;i<n1;i++)
		cin>>a[i];
	cout<<"Enter elements of second array\n";
	for(i=0;i<n2;i++)
		cin>>b[i];
	cout<<"Enter the value of x\n";
	cin>>x;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			msum = abs(a[i]+b[j]-x);
			if(msum<min)
			{
				min = msum;
				num1 = a[i];
				num2 = b[j];
			}
		}
	}
	cout<<"\nThe two numbers are\n";
	cout<<num1<<" "<<num2<<"\n";
	return 0;
}
	
/*Output:

Enter lengths of two arrays
4 4 
Enter elements of first array
1 4 5 7
Enter elements of second array
10 20 30 40
Enter the value of x
32

The two numbers are
1 30
*/
