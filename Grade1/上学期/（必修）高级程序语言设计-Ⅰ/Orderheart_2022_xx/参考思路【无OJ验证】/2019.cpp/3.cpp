#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
bool map[100001];
int main ()
{
	int num;bool flag=true;
	cin>>num;
	//埃氏素数生成表 
	memset(map,true,sizeof(map));
	map[1]=map[2]=false;
	for(int i=3;i<=num/2;i++)
	{
		if(map[i])
		{
			for(int k=2;k*i<=num;k++)
			map[k*i]=false;
		}
	}
	if(num%2==0&&num>6)
	{
		for(int k=3;k<=num/2;k++)
		{
			if(map[k]&&map[num-k])
				cout<<k<<" "<<num-k<<endl;
		}
	}
	else
	cout<<"ERROR";
    return 0;
}
