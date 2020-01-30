#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int t,n,i,j,ele,l,h,mid,a[50];
	cout<<"Enter the number of testcases\n";
	cin>>t;
	for(i=0;i<t;i++)
	{
		cout<<"\nEnter the number of elements in array and element to be searched\n";
		cin>>n>>ele;
		l = 0;
		h = n-1;
		cout<<"Enter the elements of array\n";
		for(j=0;j<n;j++)
			cin>>a[j];
		while(l<=h)
		{
			mid = (int)(l+h)/2;
			if(a[mid]==ele)
			{
				cout<<"1 (Element is present)\n";
				break;
			}
			else if(a[mid]<ele)
				l = mid+1;
			else 
				h = mid-1;
		}
		if(l>h)
			cout<<"-1 (Element is not present)\n";
	}
	return 0;
}
