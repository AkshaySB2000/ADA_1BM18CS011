#include<algorithm>
#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,a[30][30],q[30],f=0,r=-1;
void lextopo()
{
	vector<int> indeg(n,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==1)
				indeg[j]++;
		}	
	}
	for(int i=0;i<n;i++)
	{
		if(indeg[i]==0)
			q[++r]=i;
	}
	int c=0;
	vector<int> toporder;
	while(f<=r)
	{
		int min=q[f++];
		
		toporder.push_back(min);
		for(int i=0;i<n;i++)
		{
			if(a[min][i]==1)
			{
				indeg[i]--;
				if(indeg[i]==0)
					q[++r]=i;
			}	
		}
		c++;
	}
	if(c!=n)
	{
		cout<<-1<<endl;
		return;
	}
	for(int i=0;i<toporder.size();i++)
		cout<<toporder[i]<<" ";
			
}
int main()
{
	int p,x,y,i;
	vector<pair<int, int>> pre;
	cout<<"Enter the no of tasks\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			a[i][j]=0;
	}
	cout<<"Enter the number of pairs\n";
	cin>>p;
	cout<<"Enter the pairs\n";
	for(i=0;i<p;i++)
	{
		cin>>x>>y;
		pre.push_back(make_pair(x,y));
		a[y][x]=1;
	}
	cout<<"\nThe ordering of tasks to be picked to finish all tasks is\n";
	lextopo();
	cout<<endl;
	return 0;
}

/*Output:

Enter the no of tasks
6
Enter the number of pairs
5
Enter the pairs
2 3
2 5
1 5
1 3
3 4

The ordering of tasks to be picked to finish all tasks is
0 4 5 3 1 2
*/
