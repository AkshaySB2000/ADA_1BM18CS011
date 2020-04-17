#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lis(int a[], int n);
int main()  
{  
	int n,i;
	cout<<"Enter the size of the array\n";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of the array\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nThe length of the longest increasing subsequence of the given sequence = "<<lis(a,n)<<endl;
	return 0;
}
int lis(int a[], int n)  
{  
	int lis[n],i,j; 
	lis[0] = 1;    
	for(i=1;i<n;i++)  
	{ 
		lis[i] = 1; 
		for(j=0;j<i;j++)   
			if(a[i]>a[j] && lis[i]<lis[j]+1)  
				lis[i] = lis[j] + 1;  
	} 
	return *max_element(lis,lis+n); 
}  

/*Output:

Enter the size of the array
6
Enter the elements of the array
5 2 3 7 9 1

The length of the longest increasing subsequence of the given sequence = 4
*/
