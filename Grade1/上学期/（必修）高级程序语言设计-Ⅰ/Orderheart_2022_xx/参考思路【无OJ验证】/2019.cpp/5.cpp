#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct node
{
	string num;
	int  sum = 1;
	bool flag=true;
};
bool test(struct node *m,int n)
{
	int len=m[n].num.size()-1;
	for(int z=0;z<=len;z++,len--)
		if(m[n].num[z]!=m[n].num[len])
			return false;
	return true;
}
bool check(string a,string b){
	int len1 = a.size();
	int len2 = b.size();
	if(len1 != len2)
		return len1 > len2;
	else{
		for(int i = 1; i < len1; i ++)
			if(a[i] != b[i])
				return a[i] > b[i];
	}
	return true;
}
int main ()
{
	struct node  a[100],b[100];
	char ch,map[10000];
	int step=0,total=1;
	while((ch=getchar())!=EOF)
	map[++step]=ch;
	
	for(int i=1;i<=step;i++)
	{
		if(map[i]<='9'&&map[i]>='0')
		{
			while(map[i]<='9'&&map[i]>='0')
			{
				a[total].num+=map[i];
				i++;
			}
		total++;
		}
	}	
	total--;
	
	for(int j=1;j<=total;j++)
	a[j].flag=test(a,j);
	
	
	for(int i=1;i<=total-1;i++)
	{
		for(int j=i+1;j<=total;j++)
		{
			if(a[i].flag && a[j].flag && a[i].num == a[j].num)
			{
			a[i].sum++;
		    }
		}
	}
	// for(int i = 1; i <= total; i ++)
	// 	cout << a[i].num << " " << a[i].flag << " " << a[i].sum << endl;
	
	int max=1,idx = 0;
	for(int i = 1; i<= total; i ++)
		if(a[i].sum > a[max].sum)
			max = i;

	for(int i=1;i<=total;i++)
	if(a[i].sum == a[max].sum && a[i].flag)
		b[++idx] = a[i];

	// for(int i = 1; i <= idx; i ++)
	// 	cout << b[i].num << endl;

	for(int i = 1; i < idx; i ++)
		for(int j = i + 1; j <=idx ; j ++)
			if(check(b[i].num,b[j].num)){
					node tmp = b[i];
					b[i] = b[j];
					b[j] = tmp;
			}
	
	for(int i = 1; i <= idx; i ++)
		cout << b[i].num <<" " <<  b[i].sum << endl;
	//cout<<a[i].num<<" "<<a[i].sum<<endl;
	//max=i;
	
	
	
    return 0;
}
