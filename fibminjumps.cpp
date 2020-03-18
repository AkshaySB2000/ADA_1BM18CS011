#include<algorithm>
#include<iostream> 
using namespace std;  
int minjumps(int a[], int n);
int main() 
{ 
	int a[300],n,i;
	cout<<"Enter the value of n\n";
	cin>>n;
	cout<<"Enter the elements/indices of the array\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"\nThe minimum number of jumps required = "<<minjumps(a,n)<<"\n"; 
        return 0;
} 
int minjumps(int a[], int n) 
{
	int fib[30],i,j,mj[n+2]; 
        fib[0] = 0; 
        fib[1] = 1; 
        for(i=2;i<30;i++) 
        	fib[i] = fib[i-1]+fib[i-2]; 
 	mj[0] = 0; 
 	for(i=1;i<=n+1;i++) 
        	mj[i] = 10000; 
        for(i=1;i<=n+1;i++)
	{ 
        	for(j=1;j<30;j++)
		{ 
  			if((a[i-1]==1 || i==n+1) && (i-fib[j])>=0) 
                		mj[i] = min(mj[i],1+mj[i-fib[j]]);
		} 
    	} 
  	if(mj[n+1]!=10000) 
        	return mj[n+1]; 
    	else
        	return -1; 
} 

/*Output:

Enter the value of n
11
Enter the elements/indices of the array
0 0 0 1 1 0 1 0 0 0 0

The minimum number of jumps required = 3
*/
  
