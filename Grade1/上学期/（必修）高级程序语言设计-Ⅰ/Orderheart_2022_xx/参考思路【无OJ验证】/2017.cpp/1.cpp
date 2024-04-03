#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
int book[10001];
int main()
{
	int n,num,ch;
	cin>>n;
	while(n--)
	{
		cin>>num;
		memset(book,0,sizeof(book));
		for(int i=1;i<=num;i++)
		{
			cin>>ch;
			book[ch]++;
		}
		for(int i=1;i<=10000;i++)
		{
			if(book[i])
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
