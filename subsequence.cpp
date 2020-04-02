#include<algorithm>
#include<iostream>
int subsequence(char s[], int n);
using namespace std;
int main()
{
	int n,i;
	char s[1000];
	cout<<"Enter the number of characters in the sequence\n";
	cin>>n;
	cout<<"Enter the string/sequence\n";
	for(i=0;i<n;i++)		
		cin>>s[i];
	cout<<"\nThe length of longest palindromic subsequence = "<<subsequence(s,n)<<"\n";
	return 0;
}
int subsequence(char s[], int n)
{
	int i,j,cl,l[n][n];
	for(i=0;i<n;i++)
		l[i][i] = 1;
	for(cl=2;cl<=n;cl++)
	{
		for(i=0;i<n-cl+1;i++)
		{
			j = i+cl-1;
			if(s[i]==s[j] && cl==2)
				l[i][j] = 2;
			else if(s[i]==s[j])
				l[i][j] = l[i+1][j-1]+2;
			else
				l[i][j] = max(l[i][j-1],l[i+1][j]);
		}
	}
	return l[0][n-1];
}	

/*Output:

Enter the number of characters in the sequence
11
Enter the string/sequence
ENGINEERING

The length of longest palindromic subsequence = 6
*/
