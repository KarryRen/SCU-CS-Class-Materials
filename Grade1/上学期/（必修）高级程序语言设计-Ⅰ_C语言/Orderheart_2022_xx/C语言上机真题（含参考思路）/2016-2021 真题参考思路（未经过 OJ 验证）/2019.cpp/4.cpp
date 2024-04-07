#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
char map[1000][1000];
struct node 
{
	int num;
	char ch;
};
int main ()
{
	memset(map,' ',sizeof(map));
	int n;
    cin>>n;
	struct node a[n+1];
	int max=0,min=0; 
	for(int p=1;p<=n;p++)
	{
		scanf("%d",&a[p].num);
		scanf("%c",&a[p].ch);
		if(a[p].num>max)
		max=a[p].num;
		if(a[p].num<min)
		min=a[p].num;
		if(a[p].ch==' '||a[p].ch=='\n')
		a[p].ch='+';
	}
	min=fabs(min);
	
	for(int z=1;z<=2*n-1;z++)
	map[max+1][z]='-';
	
	for(int i=1,step=1;i<=n;i++,step+=2)
	{
		if(a[i].num>0)
		{
		int ny=max;
		while(a[i].num>0)
		{
			map[ny][step]=a[i].ch;
			ny--;a[i].num--;
		}
		}
		if(a[i].num<0)
		{
			a[i].num=abs(a[i].num);
			int ny=max+2;
			while(a[i].num>0)
			{
				map[ny][step]=a[i].ch;
				ny++;a[i].num--;
			}
		}
	}	
	for(int q=1;q<=max+min+1;q++)
	{
		for(int j=1;j<=2*n-1;j++)
		cout<<map[q][j];
		cout<<endl;
	}
	
    return 0;
}
