#include<algorithm>
#include<iostream>
using namespace std;
int getmobile(int a[], int n, int dir[]);
int searchpos(int a[], int n, int mobile);
void printoneperm(int a[], int dir[], int n);
int fact(int n);
int main()
{
	int n,i,a[20],dir[20],f;
	cout<<"Enter the value of n\n";
	cin>>n;
	cout<<"\nAll the possible permutations using Johnson & Trotter algorithm are\n";
	for(i=0;i<n;i++)
	{
		a[i] = i+1;
		dir[i] = 0;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	f = fact(n);
	for(i=1;i<f;i++)
		printoneperm(a,dir,n);
	return 0;
}
int fact(int n)
{
	int f;
	if(n==1)
		return 1;
	f = n*fact(n-1);
	return f;
}
void printoneperm(int a[], int dir[], int n)
{
	int mobile,pos,i;
	mobile = getmobile(a,n,dir);
	pos = searchpos(a,n,mobile);
	if(dir[a[pos-1]-1]==0)
		swap(a[pos-2],a[pos-1]);
	else if(dir[a[pos-1]-1]==1)
		swap(a[pos],a[pos-1]);
	for(i=0;i<n;i++)
	{
		if(a[i]>mobile)
		{
			if(dir[a[i]-1]==0)
				dir[a[i]-1] = 1;
			else if(dir[a[i]-1]==1)
				dir[a[i]-1] = 0;
		}
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";	
	cout<<endl;
}
int getmobile(int a[], int n, int dir[])
{
	int prevmob = 0,mobile = 0,i;
	for(i=0;i<n;i++)
	{
		if(dir[a[i]-1]==0 && i!=0)
		{
			if(a[i]>a[i-1] && a[i]>prevmob)
			{
				mobile = a[i];
				prevmob = mobile;
			}
		}
		else if(dir[a[i]-1]==1 && i!=n-1)
		{
			if(a[i]>a[i+1] && a[i]>prevmob)
			{
				mobile = a[i];
				prevmob = mobile;
			}
		}
	}
	if(prevmob==0 && mobile==0)
		return 0;
	else
		return mobile;
}
int searchpos(int a[], int n, int mobile)
{
	int pos=-1,i;
	for(i=0;i<n;i++)
	{
		if(a[i]==mobile)
			pos = i;
	}
	if(pos!=-1)
		return (pos+1);
	return -1;
}

/*Output:

Enter the value of n
4

All the possible permutations using Johnson & Trotter algorithm are
1 2 3 4 
1 2 4 3 
1 4 2 3 
4 1 2 3 
4 1 3 2 
1 4 3 2 
1 3 4 2 
1 3 2 4 
3 1 2 4 
3 1 4 2 
3 4 1 2 
4 3 1 2 
4 3 2 1 
3 4 2 1 
3 2 4 1 
3 2 1 4 
2 3 1 4 
2 3 4 1 
2 4 3 1 
4 2 3 1 
4 2 1 3 
2 4 1 3 
2 1 4 3 
2 1 3 4 
*/







	
