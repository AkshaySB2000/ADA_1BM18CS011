#include<algorithm>
#include<iostream>
using namespace std;
int G[10][10],visited[10];
int flag=1;
void DFS(int i,int n)
{
int j;
visited[i]=1;
for(j=0;j<n;j++)
{
if(visited[j]==1&&G[i][j]==1)
{
flag=0;
break;
}
if(visited[j]==0&&G[i][j]==1)
DFS(j,n);
}
}




int main()
{
    int i,j,n;
    cout<<"Enter number of vertices\n";
   
	cin>>n;
 
    
	cout<<"Enter adjacency matrix of the graph\n";
   
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			cin>>G[i][j];
 
    
   for(i=0;i<n;i++)
        visited[i]=0;
 
    DFS(0,n);
    if(flag==0)
    cout<<"\nCycle exists";
    else
    cout<<"\nCycle doesnt exist";
    return 0;
}
