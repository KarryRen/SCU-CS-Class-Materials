#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;
int main ()
{
	int m;
	int org[21],turn[21];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>org[i];
		turn[i]=fabs(org[i]);
	}
	int flag=1;
	for(int j=1;j<=m;j++)
	if(turn[j]>turn[flag])
	flag=j;
	
	cout<<org[flag];

    return 0;
}
