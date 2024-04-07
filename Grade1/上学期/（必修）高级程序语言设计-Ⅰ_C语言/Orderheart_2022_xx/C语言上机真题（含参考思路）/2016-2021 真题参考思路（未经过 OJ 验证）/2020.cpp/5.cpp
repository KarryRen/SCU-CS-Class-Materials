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
    string grade;
    int level;
};
int turn(string ch)
{
    int len= ch.size()-1;
    int total=0;
    for(int k=0;k<=len;k++)
        total+=(total*10)+ch[k]-'0';
    return total;
}
bool cmp(struct node cc,struct node dd)
{
	bool flag1=true,flag2=true;
	int ccg,ddg;
	if(cc.grade=="n/a")
	{
		ccg=-1;flag1=false;
	}
	if(dd.grade=="n/a")
	{
		ddg=-1;flag2=false;
	}
	if(flag1)
	ccg=turn(cc.grade);
	if(flag2)
	ddg=turn(dd.grade);
	
	if(ccg>ddg)
	return true;
	else
	return false;
}
int main ()
{
    int n;string ch;
    cin>>n;
    cin>>ch;
    struct node s[n+1];
    
    for(int i=1;i<=n;i++)
        cin>>s[i].name>>s[i].id>>s[i].grade;
    
	sort(s+1,s+n+1,cmp);
	
	int temp=1;s[1].level=1;//标记排名 
	
	for(int i=2;i<=n;i++)
	{
		if(s[i].grade==s[i-1].grade)
		s[i].level=temp;
		else
		{
			temp++;
			s[i].level=temp;
		}
	}
    int tch=turn(ch);
    if(tch<=100&&tch>=0)//查找成绩
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i].grade.find(ch)!=string::npos)
			{
				cout<<s[i].name<<" "<<s[i].id<<" "<<s[i].grade<<" "<<s[i].level<<endl;
			}
		}
	}
    else
    {
    	//先查找姓名
		for(int i=1;i<=n;i++)
		{
			if(s[i].name.find(ch)!=string::npos)
				cout<<s[i].name<<" "<<s[i].id<<" "<<s[i].grade<<" "<<s[i].level<<endl;
			else if(s[i].id.find(ch)!=string::npos)
					cout<<s[i].name<<" "<<s[i].id<<" "<<s[i].grade<<" "<<s[i].level<<endl;
		 } 
	}

    return 0;
}
