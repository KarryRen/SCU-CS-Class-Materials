#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
const int N = 100;
int f[N];
int main()
{
	int n,num,sum=1;
	cin>>n;
	f[1]=1;
	for(int j=2;j<=99;j++)
	f[j]=(f[j-1]*j)%1000000;
	while(n--)
	{
		cin>>num;
		for(int i=2;i<=num;i++)
			sum=(sum+f[i])%1000000;
		cout<<sum<<endl;
	}
	return 0;
}
