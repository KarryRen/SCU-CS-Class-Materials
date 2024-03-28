#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;

int main()
{
		int n,k;
		cin>>n>>k;
		int a[n+1][n+1],c[n+1][n+1],temp[n+1][n+1];
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			c[i][j]=a[i][j];
		}
		
		for(int q=2;q<=k;q++)
		{
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			temp[i][j]=c[i][j];
			memset(c,0,sizeof(c));
			
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			c[i][j]+=a[i][k]*temp[k][j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			cout<<c[i][j]<<" ";
			cout<<endl;
		}
	
		return 0;
	
}
