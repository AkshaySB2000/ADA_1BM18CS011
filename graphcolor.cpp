#include<algorithm>
#include<iostream>
using namespace std;
int n;
bool a[30][30];
bool issafe(int v, bool a[][30], int color[], int c);
void printsolution(int color[]);
bool graphcolor(bool a[][30], int m, int color[], int v);
int main()
{
	int m,i,j;
	cout<<"Enter the no.of colors\n"; 
	cin>>m;
	cout<<"Enter the no.of vertices\n"; 
	cin>>n;
	int color[n];
	cout<<"Enter the adjacency matrix:"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
			
		}
	}
    	for(i=0;i<n;i++) 
       		color[i] = 0; 
    	if(graphcolor(a, m, color, 0) == false) 
    	{ 
      		cout<<"\nSolution does not exist\n"; 
      	} 
     	else
    		printsolution(color); 
    	return 0;
} 
bool issafe(int v, bool a[][30], int color[], int c) 
{ 
	int i;
   	for(i=0;i<n;i++) 
        if(a[v][i] && c == color[i]) 
        	return false; 
    	return true; 
} 
void printsolution(int color[]) 
{ 
	    int i;
	    cout<<"\nThe assigned colors are: "<<endl;
	    for (i=0;i<n;i++) 
      	    cout<<color[i]<<" ";
    	    cout<<endl; 
} 
bool graphcolor(bool a[][30], int m, int color[], int v) 
{     
	int c;
	if(v==n) 
        	return true; 
	for (c=1;c<=m;c++) 
    	{ 
                if(issafe(v,a,color,c)) 
        	{ 
           		color[v] = c; 
  			if(graphcolor(a,m,color,v+1)==true) 
             		return true; 
  			color[v] = 0; 
  		} 
    	} 
  	return false; 
} 

/*Output:

Enter the no.of colors
3
Enter the no.of vertices
5
Enter the adjacency matrix:
0 1 0 1 1
1 0 1 1 0
0 1 0 1 0
1 1 1 0 1
1 0 0 1 0

The assigned colors are: 
1 2 1 3 2 
*/



