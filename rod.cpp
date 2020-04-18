#include<algorithm>
#include<iostream>
int cutrod(int price[], int n);
using namespace std;
int main()
{
	int n,i;
	cout<<"Enter the length of the rod\n";
	cin>>n;
	int price[n];
	cout<<"Enter the price of each piece\n";
	for(i=0;i<n;i++)
		cin>>price[i];
	cout<<"\nThe maximum obtainable value = "<<cutrod(price,n)<<"\n";
	return 0;
}
int cutrod(int price[], int n) 
{ 
	int val[n+1]; 
   	val[0] = 0; 
   	int i,j; 
   	for(i=1;i<=n;i++) 
   	{ 
       		int maximum = -99; 
       		for(j=0;j<i;j++) 
         		maximum = max(maximum,price[j]+val[i-j-1]); 
       		val[i] = maximum; 
   	} 
  
   	return val[n]; 
} 

/*Output:

Enter the length of the rod
9
Enter the price of each piece
2 4 6 7 7 12 13 16 17

The maximum obtainable value = 18
*/


