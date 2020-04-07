#include<algorithm>
#include<iostream>
bool partition(int a[], int n);
using namespace std;
int main()
{
	int n,i;
	cout<<"Enter the number of elements\n";
	cin>>n;
	int a[n];
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	if(partition(a,n)==true)
		cout<<"\nThe array can be partitioned into two subsets having equal sum\n";
	else
		cout<<"\nThe array cannot be partitioned\n";
	return 0;
}
bool partition(int a[], int n)
{
	int i,j,sum = 0;
	for(i=0;i<n;i++)
		sum += a[i];
	if(sum%2!=0 || n<2)
		return false;
	bool parttable[sum/2+1][n+1];
	for(j=0;j<=n;j++)
		parttable[0][j] = true;
	for(i=1;i<=sum/2;i++)
		parttable[i][0] = false;
	for(i=1;i<=sum/2;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>=a[j-1])
				parttable[i][j] = parttable[i][j-1] || parttable[i-a[j-1]][j-1];
		}
	}
	return parttable[sum/2][n];
}
				
/*Outputs:

1. Enter the number of elements
6
Enter the elements
3 1 1 2 2 1

The array can be partitioned into two subsets having equal sum

2. Enter the number of elements
6
Enter the elements
3 2 1 2 2 1

The array cannot be partitioned
*/
		
