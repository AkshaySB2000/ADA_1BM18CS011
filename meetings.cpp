#include<algorithm>
#include<iostream>
using namespace std;
void isort(int a[],int n);
int main()
{
	int n,i,s[50],f[50],resst[50],resf[50],mnum[50],p,q;
	cout<<"Enter the total no of meetings\n";
	cin>>n;
	cout<<"Enter the start times of the meetings\n";
	for(i=0;i<n;i++)
		cin>>s[i];
	cout<<"Enter the finishing times of the meetings\n";
	for(i=0;i<n;i++)
		cin>>f[i];
	isort(s,n);
	isort(f,n);
	resst[0]=s[0];
	resf[0]=f[0];
	p=0;
	q=0;
	mnum[0]=1;
	for(i=1;i<n;i++)
	{
		if(s[i]>resf[p])
		{
			resst[++q]=s[i];
			resf[++p]=f[i];
			mnum[q]=i+1;
		}
	}
	cout<<"\nMaximum number of meetings = "<<q+1<<"\n";
	cout<<"Meeting numbers are : ";
	for(i=0;i<=q;i++)
		cout<<mnum[i]<<" ";
	cout<<endl;
	for(i=0;i<=q;i++)
	{
		cout<<"("<<resst[i]<<","<<resf[i]<<")"<<"\n";
	}
	return 0;
}
void isort(int a[],int n)
{
	int i,j,item;
	for(i=1;i<n;i++)
	{
		item = a[i];
		j=i-1;
		while(j>=0 && a[j]>item)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=item;
	}
}

