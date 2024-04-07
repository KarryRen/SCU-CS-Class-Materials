#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct node
{
	string name;
	string id;
	int grade;
};
int turn(string ch)
{
	int len= ch.size()-1;
	int total=0;
	for(int k=0;k<=len;k++)
	total+=(total*10)+ch[k]-'0';
	return total;
}

int main ()
{
	int n;
	cin>>n;
	struct node s[n+1];
	int max=1,min=1;string ch;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].name>>s[i].id>>ch;
		if(ch=="n/a")
		s[i].grade=-1;
		else
		s[i].grade=turn(ch);
		
		if(s[i].grade>s[max].grade&&s[i].grade!=-1&&s[max].grade!=-1)
		max=i;
		else if(s[i].grade==s[max].grade&&s[i].grade!=-1&&s[max].grade!=-1&&s[i].name<s[max].name)
		max=i;
		if(s[i].grade<s[min].grade&&s[i].grade!=-1&&s[min].grade!=-1)
		min=i;
		else if(s[i].grade==s[min].grade&&s[i].grade!=-1&&s[min].grade!=-1&&s[i].name>s[max].name)
		min=i;
	}
	cout<<s[max].name<<" "<<s[max].id<<endl;
	cout<<s[min].name<<" "<<s[min].id<<endl;
	
    return 0;
}
