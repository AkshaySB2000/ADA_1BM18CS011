#include<algorithm>
#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
int ptr[501]; 
void smallestrange(int arr[][100], int n, int k);
int main() 
{ 
	int k,n,i,j,arr[100][100];
	cout<<"Enter number of arrays i.e, value of k\n";
	cin>>k;
	cout<<"Enter the size of each array\n";
	cin>>n;
	cout<<"Enter elements of "<<k<<" arrays\n";
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
			cin>>arr[i][j];
	}
	smallestrange(arr,n,k); 
  	return 0; 
} 
void smallestrange(int arr[][100], int n, int k) 
{ 
    	int i,minval,maxval,minrange,minel,maxel,flag,minind; 
  	for(i=0;i<=k;i++) 
        	ptr[i] = 0; 
  	minrange = INT_MAX; 
  	while(1) 
	{ 
	        minind = -1; 
	        minval = INT_MAX; 
	        maxval = INT_MIN; 
	        flag = 0;  
	        for (i=0;i<k;i++)
		{     
        		if(ptr[i]==n) 
			{ 
                		flag = 1; 
                		break; 
            		} 
        	        if(ptr[i]<n && arr[i][ptr[i]]<minval) 
			{ 
		                minind = i;  
		                minval = arr[i][ptr[i]]; 
		        }         
            		if(ptr[i]<n && arr[i][ptr[i]]>maxval)
			{ 
                		maxval = arr[i][ptr[i]]; 
            		} 
        	}       
        	if (flag) 
            		break;   
        	ptr[minind]++;      
        	if ((maxval-minval)<minrange) 
		{ 
			minel = minval; 
            		maxel = maxval; 
            		minrange = maxel - minel; 
        	} 
    	} 
	cout<<"\nThe smallest range is ["<<minel<<","<<maxel<<"]\n"; 
} 
  
/*Output:

Enter number of arrays i.e, value of k
3
Enter the size of each array
5
Enter elements of 3 arrays
4 7 9 12 15
0 8 10 14 20
6 12 16 30 50

The smallest range is [6,8]
*/ 

