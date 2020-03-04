#include<algorithm>
#include<iostream>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[20],n,i,j,item;
	clock_t time;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	time = clock();
	for(i=1;i<n;i++)
	{
		item = a[i];
		j=i-1;
		while(j>=0 && a[j]>item)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=item;
	}
	time = clock() - time;
	cout<<"\nThe time required for insertion sort is "<<fixed<<setprecision(7)<<(float)time/CLOCKS_PER_SEC<<"\n";
	cout<<"\nThe sorted array is\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;  	
	return 0;
}
