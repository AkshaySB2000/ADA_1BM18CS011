#include<algorithm>
#include<iostream>
void xormatrix(int n);
using namespace std;
int main()
{
	int n;
	cout<<"Enter a number which is a multiple of 4\n";
	cin>>n;
	if(n%4==0)
		xormatrix(n);
	else
		cout<<"\nInvalid Input\n";
	return 0;
}
void xormatrix(int n)
{
	int a[n][n],x=0,i,j,k,l;
	for(i=0;i<n/4;i++)
	{
		for(j=0;j<n/4;j++)
		{
			for(k=0;k<4;k++)
			{
				for(l=0;l<4;l++)
				{
					a[i*4+k][j*4+l] = x;
					x++;
				}
			}
		}
	}
	cout<<"\nThe matrix in which the bitwise XOR of each row and column is the same is\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

/*Output:

Enter a number which is a multiple of 4
8

The matrix in which the bitwise XOR of each row and column is the same is
0 1 2 3 16 17 18 19 
4 5 6 7 20 21 22 23 
8 9 10 11 24 25 26 27 
12 13 14 15 28 29 30 31 
32 33 34 35 48 49 50 51 
36 37 38 39 52 53 54 55 
40 41 42 43 56 57 58 59 
44 45 46 47 60 61 62 63 
*/
