#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int a[20],n,i,j,k,temp;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the value of k\n";
	cin>>k;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	cout<<"\nThe 'k' largest elements in the array are\n";
	for(i=0;i<k;i++)	
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
	
