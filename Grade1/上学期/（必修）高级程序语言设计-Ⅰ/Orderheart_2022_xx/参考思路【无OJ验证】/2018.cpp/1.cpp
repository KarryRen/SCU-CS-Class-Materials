#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
int book[10];
int main()
{
		bool flag=false;
		int num;
		for(int i=0;i<=9;i++)
		{
			cin>>num;
			book[i]=num;
		}
		for(int i=1;i<=9;i++)
			if(book[i])
				{
					cout<<i;book[i]--;break;
				}
		for(int i=0;i<=9;i++)
		{
			if(book[i])
			{
				while(book[i])
				{
					cout<<i;book[i]--;
				}
			}
		}
		
		return 0;
	
}
