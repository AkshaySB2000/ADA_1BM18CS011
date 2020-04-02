#include<algorithm>
#include<iostream>
int knapsack(int n, int m, int w[], int p[]);
using namespace std;
int main()
{
	int n,m,os,i;
	cout<<"Enter the number of objects\n";
	cin>>n;
	cout<<"Enter the maximum capacity of the knapsack\n";
	cin>>m;
	int w[n],p[n];
	cout<<"Enter the weights of the objects\n";
	for(i=0;i<n;i++)
		cin>>w[i];
	cout<<"Enter the profits for each objects\n";
	for(i=0;i<n;i++)
		cin>>p[i];
	cout<<endl;
	os = knapsack(n,m,w,p);
	cout<<"\nThe optimal solution from selected objects/items produces profit = "<<os<<"\n";
	return 0;
}
int knapsack(int n, int m, int w[], int p[])
{
	int x[n],v[n+1][m+1],i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				v[i][j] = 0;
			else if(w[i-1]>j)
				v[i][j] = v[i-1][j];
			else 
				v[i][j] = max(v[i-1][j],(v[i-1][j-w[i-1]]+p[i-1]));
		}
	}
	for(i=0;i<n;i++)
		x[i] = 0;
	i = n;
	j = m;
	while(i!=0 && j!=0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			x[i-1] = 1;
 			j = j-w[i-1];
		}
		i--;
	}
	for(i=0;i<n;i++)
	{
		if(x[i]==1)
			cout<<"Object "<<i+1<<" is selected\n";
		else
			cout<<"Object "<<i+1<<" is not selected\n";
	}
	return v[n][m];
}

/*Output:

Enter the number of objects
4
Enter the maximum capacity of the knapsack
5
Enter the weights of the objects
2 1 3 2
Enter the profits for each objects
12 15 25 10

Object 1 is not selected
Object 2 is selected
Object 3 is selected
Object 4 is not selected

The optimal solution from selected objects/items produces profit = 40
*/

