#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;

int main()
{
		int n;cin>>n;
		int a[n+1],sum=1;
		
		for(int i=1;i<=n;i++)
		cin>>a[i];
		
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			sum++;
		}
		cout<<sum;
		return 0;
	
}
