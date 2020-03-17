#include<algorithm>
#include<iostream>
float mergemedian(int a[], int b[], int n);
float median(int arr[], int n);
using namespace std;
int main()
{
	int a[100],b[100],n,i;
	float median;
	cout<<"Enter the size of the arrays\n";
	cin>>n;
	cout<<"Enter the elements of the first array in ascending order\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cout<<"Enter the elements of the second array in ascending order\n";
	for(i=0;i<n;i++)
		cin>>b[i];
	sort(b,b+n);
	median = mergemedian(a,b,n);
	cout<<"\nThe median of the merged array = "<<median<<"\n";
	return 0;
}
float mergemedian(int a[], int b[], int n) 
{
	float ma,mb; 
	if(n<=0) 
	        return -1; 
	if(n==1) 
        	return (float)(a[0]+b[0])/2; 
	if(n==2) 
        	return (float)(max(a[0],b[0])+min(a[1],b[1]))/2; 
	ma = median(a,n);  
	mb = median(b,n);  
	if(ma==mb) 
        	return ma; 
	if(ma<mb) 
	{ 
        	if(n%2==0) 
        		return mergemedian(a+n/2-1,b,n-n/2+1);
		else
		       	return mergemedian(a+n/2,b,n-n/2); 
    	} 
	if(n%2==0) 
	        return mergemedian(b+n/2-1,a,n-n/2+1); 
	else    	
		return mergemedian(b+n/2,a,n-n/2); 
} 
float median(int arr[], int n) 
{ 
	if(n%2==0) 
        	return (float)(arr[n/2]+arr[n/2-1])/2; 
    	else
        	return arr[n/2]; 
} 

/*Output:

Enter the size of the arrays
5
Enter the elements of the first array in ascending order
2 3 5 7 10
Enter the elements of the second array in ascending order
4 6 9 11 15

The median of the merged array = 6.5
*/
  
