#include<algorithm>
#include<iostream>
int bsearch(int a[], int n, int key);
using namespace std;
int main()
{
	int a[2],b[20],c[20],com[20],n1,n2,n3,i,j=0,item,item1,item2;
	com[0] = -1;
	cout<<"Enter lengths of three arrays\n";
	cin>>n1>>n2>>n3;
	cout<<"Enter elements of first array\n";
	for(i=0;i<n1;i++)
		cin>>a[i];
	cout<<"Enter elements of second array\n";
	for(i=0;i<n2;i++)
		cin>>b[i];
	cout<<"Enter elements of third array\n";
	for(i=0;i<n3;i++)
		cin>>c[i];
	for(i=0;i<n1;i++)
	{
		item = a[i];		
		item1 = bsearch(b,n2,item);
		item2 = bsearch(c,n3,item);
		if(item1==item && item2==item)
		{
			com[j] = item;
			j++;
		}
	}
	if(com[0]==-1)
		cout<<"No common elements\n";
	else
	{
		cout<<"\nThe common elements in all three arrays are\n";
		for(i=0;i<j;i++)
			cout<<com[i]<<" ";
		cout<<endl;
	}
	return 0;
}
int bsearch(int a[], int n, int key)
{
	int mid,low,high;
	low = 0;
	high = n-1;
	while(low<=high)
	{
		mid = (int)(low+high)/2;
		if(a[mid]==key)
			return a[mid];
		else if(a[mid]<key)
			low = mid+1;
		else
			high = mid-1;
	}
	return -99;
}

/*Output:

Enter lengths of three arrays
6 5 8
Enter elements of first array
1 5 10 20 40 80
Enter elements of second array
6 7 20 80 100
Enter elements of third array
3 4 15 20 30 40 80 120

The common elements in all three arrays are
20 80 

		
