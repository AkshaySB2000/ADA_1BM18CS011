#include<algorithm>
#include<iostream>
using namespace std;
int a[20][20],n,visited[20],s[20],top=-1,c=1,flag=0;
void dfs(int v)
{
	int i,j;
	visited[v]=1;
	s[++top]=v;
	for(i=1;i<=n;i++)
	{
		if(a[v][i]==1 && !visited[i])
		{
			flag=1;
			c++;
			//cout<<i<<" ";
			dfs(i);
		}
	}
	if(flag==0)
	{
		for(j=1;j<=n;j++)
		{
			if(a[s[top]][j]==1 && !visited[j])
			{
				flag==1;
				c++;
				//cout<<j<<" ";
				dfs(j);
			}
		}
		if(flag==0)
			top--;
	}
}
int main()
{
	int v,i,j;
	cout<<"Enter the number of vertices\n";
	cin>>n;
	cout<<"Enter the adjacency matrix\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	dfs(1);
	if(c==n)
		cout<<"\nThe graph is a connected graph\n";
	else
		cout<<"\nThe graph is not a connected graph\n";
	return 0;
}

