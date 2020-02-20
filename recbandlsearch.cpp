#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
#include<time.h>
int bsearch(int a[],int l,int h,int key);
int lsearch(int a[],int i,int n,int key);
using namespace std;
int main()
{
	srand(time(0));	
	int a[20],n,i,pos,key;
	clock_t time;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
	{		
		a[i] = rand()%1000;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Enter the key element\n";
	cin>>key;
	time = clock();
	pos = lsearch(a,0,n,key);
	time = clock() - time;
	cout<<"\nThe time taken for linear search = "<<fixed<<setprecision(10)<<(float)time/CLOCKS_PER_SEC<<"\n";
	if(pos!=-1)
		cout<<"\nThe key element is present at position "<<pos<<" after linear search\n";
	else
		cout<<"\nThe key element is not present in the array\n";
	sort(a,a+n);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	time = clock();
	pos = bsearch(a,0,n-1,key);
	time = clock() - time;
	cout<<"\nThe time taken for binary search = "<<fixed<<setprecision(10)<<(float)time/CLOCKS_PER_SEC<<"\n";
	if(pos!=-1)
		cout<<"\nThe key element is present at position "<<pos<<" after binary search\n";
	else
		cout<<"\nThe key element is not present in the array\n";
	return 0;
}
int bsearch(int a[], int l, int h, int key)
{
	int mid;
	if(l<=h)
	{
		mid = (l+h)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]<key)
			return bsearch(a,mid+1,h,key);
		else 
			return bsearch(a,l,mid-1,key);
	}
	return -1;
}
int lsearch(int a[],int i,int n,int key)
{
	int pos;
	if(i<n)
	{
		if(a[i]==key)
		{
			pos = i;
			return pos;
		}
		else
			return lsearch(a,i+1,n,key);
	}
	return -1;
}
	
