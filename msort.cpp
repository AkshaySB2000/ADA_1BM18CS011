#include<algorithm>
#include<iostream>
#include<ctime>
#include<time.h>
#include<bits/stdc++.h>
void merge(int low, int mid, int high, int a[]);
void mergesort(int low, int high, int a[]);
using namespace std;
int main()
{
	srand(time(0));	
	int n,i,low,high;
	clock_t time;
	cout<<"Enter the number of elements\n";
	cin>>n;
        int a[n];
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
	{
		a[i] = rand()%1000;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	low = 0;
	high = n-1;
	time = clock();
	mergesort(low,high,a);
	time = clock()-time;
	cout<<"\nThe time required for merge sort is "<<fixed<<setprecision(7)<<(float)time/CLOCKS_PER_SEC<<"\n";
	cout<<"\nThe sorted array is\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
void mergesort(int low, int high, int a[])
{
	int mid;
	if(low<high)
	{
		mid = (int)(low+high)/2;
		mergesort(low,mid,a);
		mergesort(mid+1,high,a);
		merge(low,mid,high,a);
	}
}
void merge(int low, int mid, int high, int a[])
{
	int i,j,k,t[1000];
	i = low;
	j = mid+1;
	k = low;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			t[k] = a[i];
			i++;
		}
		else
		{
			t[k] = a[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		t[k] = a[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		t[k] = a[j];
		k++;
		j++;
	}
	for(i=low;i<=high;i++)
		a[i] = t[i];
}
	
/*Output:

Enter the number of elements
10
Enter the elements
403 703 153 617 839 920 460 157 540 292 

The time required for merge sort is 0.0000020

The sorted array is
153 157 292 403 460 540 617 703 839 920 
*/	
	
