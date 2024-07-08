#include<bits/stdc++.h>
using namespace std;
const int maxn=100111;
bool a[maxn];
void ass()
{
	for(int i=0;i<=maxn;i++)a[i]=true;
	a[0]=a[1]=false;
	for(int i=2;i<=maxn;i++)
	{
		if(a[i]){
			for(int j=2*i;j<=maxn;j+=i)
			{
				a[j]=false;
			}
		}
	}
}//a[i]存放i是1否0为素数 
int main()
{
	int n,t;
	cin>>n;
	ass();
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(a[t])cout<<t<<" ";
	}

return 0;
}

