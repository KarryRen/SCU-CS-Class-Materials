#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;

int main()
{
		int n,w;
		while(1)
		{
			cin>>w>>n;
			int a[n+1],b[n+1];
			for(int i=1;i<=n;i++)
				{
					cin>>a[i];b[i]=a[i];
				}
			if(w%2==0)
			{
				cout<<"ERROR"<<endl;
				return 0;
			}
				
		if(w>n)
			{
				for(int i=1;i<=n;i++)
				cout<<a[i]<<" ";
				cout<<endl;
			}
		else
			{
				for(int k=1;k+w-1<=n;k++)
				{
					int tmp[w+1];int num=0;
					for(int p=k;p<k+w;p++)
					tmp[++num]=a[p];
					
					sort(tmp+1,tmp+w+1);
					b[k+(w/2)]=tmp[w/2+1];
				}
				
				for(int i=1;i<=n;i++)
				cout<<b[i]<<" ";
				cout<<endl;
			}
		}
}
