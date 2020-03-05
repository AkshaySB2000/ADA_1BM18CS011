#include<algorithm>
#include<iostream>
using namespace std;
void bfs(int v, int n, int f, int r, int visited[], int a[][20], int q[]);
int main()
{ 
	int a[20][20],q[20],visited[20],r=-1,f=0,i,j,n,v;  
        cout<<"Enter no. of vertices\n"; 
        cin>>n; 
        for(i=1;i<=n;i++) 
        { 
   	     q[i]=0; 
             visited[i]=0; 
        } 
        cout<<"\nEnter Adjacency Matrix of the graph\n"; 
        for(i=1;i<=n;i++)
	{ 
	        for(j=1;j<=n;j++)
		{ 
                cin>>a[i][j]; 
                } 
        } 
        cout<<"\nEnter the starting node of your choice : "; 
        cin>>v; 
        bfs(v,n,f,r,visited,a,q); 
        cout<<"\nAll the nodes reachable from "<<v<<"->"<<n<<" are\n"; 
        for(i=1;i<=n;i++)
	{ 
	        if(visited[i]) 
                cout<<i<<" "; 
        } 
	cout<<endl;
      	return(0); 
}
void bfs(int v, int n, int f, int r, int visited[], int a[][20], int q[])
{ 
	int i,j;
	for(i=1;i<=n;i++)
	{
                if(a[v][i] && !visited[i]) 
               		q[++r]=i; 
                if(f<=r)
		{ 
	                 visited[q[f]]=1; 
	                 bfs(q[f++],n,f,r,visited,a,q); 
                }  
        }
}

/*Enter no. of vertices
5

Enter Adjacency Matrix of the graph
0 1 0 0 0 
0 0 0 1 0 
1 1 0 0 0 
0 0 0 0 0
0 0 1 0 0

Enter the node of ur Choice : 1

All the nodes reachable from 1->5 are
2 4*/
