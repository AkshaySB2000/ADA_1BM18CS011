#include<algorithm>
#include<iostream>
using namespace std;
int distance(string a, string b, int n, int m);
int minimum(int p, int q, int r);
int main()
{
	string a,b;
	int dist,n,m;
	cout<<"Enter the first string\n";
	getline(cin,a);
	cout<<"Enter the second string\n";
	getline(cin,b);
	n = a.length();
	m = b.length();
	dist = distance(a,b,n,m);
	cout<<"The minimum number of edits required = "<<dist<<"\n";
	return 0;
}
int minimum(int p, int q, int r)
{
	return min(min(p,q),r);
}
int distance(string a, string b, int n, int m)
{
	if(m==0)
		return n;
	if(n==0)
		return m;
	if(a[n-1]==b[m-1])
		return distance(a,b,n-1,m-1);
	return 1+minimum(distance(a,b,n,m-1),distance(a,b,n-1,m),distance(a,b,n-1,m-1));
}

/*Output:

Enter the first string
akshay
Enter the second string
abhaya
The minimum number of edits required = 3
*/

