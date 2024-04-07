#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;
int main ()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a[3];
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
    return 0;
}
