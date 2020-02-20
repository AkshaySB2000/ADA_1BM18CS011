#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int a[20],n,i,j,k,temp,min;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the value of k\n";
	cin>>k;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	cout<<"\nThe "<<k<<" largest elements in the array are\n";
	for(i=n-1;i>n-k-1;i--)	
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
	
