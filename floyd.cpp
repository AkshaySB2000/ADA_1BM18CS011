#include<algorithm>
#include<iostream>
using namespace std;
void floyd(int n, int a[][20]);
int main()
{ 
	int a[20][20],q[20],i,j,n;  
        cout<<"Enter the number of vertices of the directed/undirected graph\n"; 
        cin>>n; 
	cout<<"\nEnter the adjacency matrix of the graph (Enter 10000 as the weight if there is no edge between the vertices)\n"; 
        for(i=0;i<n;i++)
	{ 
	        for(j=0;j<n;j++)
	        	cin>>a[i][j];  
        }
	floyd(n,a);
	return 0;
}
void floyd(int n, int a[][20])
{
	int i,j,k,d[20][20];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			d[i][j] = a[i][j];
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				d[i][j] = min(d[i][j],(d[i][k]+d[k][j]));
		}
	}
	cout<<"\nThe distance matrix of shortest paths of the given graph is\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;
	}
}
 
/*Output:

1.
Enter the number of vertices of the directed/undirected graph
5

Enter the adjacency matrix of the graph (Enter 10000 as the weight if there is no edge between the vertices)
0 10000 5 7 2
10000 0 10000 1 10
5 10000 0 3 10000
7 1 3 0 10000
2 10 10000 10000 0

The distance matrix of shortest paths of the given graph is
0 8 5 7 2 
8 0 4 1 10 
5 4 0 3 7 
7 1 3 0 9 
2 10 7 9 0 

2.
Enter the number of vertices of the directed/undirected graph
4

Enter the adjacency matrix of the graph (Enter 10000 as the weight if there is no edge between the vertices)
0 10000 3 10000 
2 0 10000 10000
10000 7 0 1
6 10000 10000 0

The distance matrix of shortest paths of the given graph is
0 10 3 4 
2 0 5 6 
7 7 0 1 
6 16 9 0 
*/
