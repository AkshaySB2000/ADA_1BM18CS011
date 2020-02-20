#include<algorithm>
#include<iostream>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[20],n,i,j,temp,min;
	clock_t time;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	time = clock();
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
	time = clock() - time;
	cout<<"\nThe time required for selection sort is "<<fixed<<setprecision(10)<<(float)time/CLOCKS_PER_SEC<<"\n";
	cout<<"\nThe sorted array is\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;  	
	return 0;
}
	


