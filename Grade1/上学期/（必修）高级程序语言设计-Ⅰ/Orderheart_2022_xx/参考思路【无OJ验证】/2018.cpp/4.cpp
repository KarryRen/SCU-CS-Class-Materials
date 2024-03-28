#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
string mon[]={"0","January","February","March","April","May","June","July","August","September","October","November","December"};
int ping[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int run[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool test(int x)
{
	return (x%400==0||(x%4==0&&x%100!=0))?true:false;
}
int date(int y1,int m1,int d1,int y2,int m2,int d2)//y1>y2
{
	int mod1=0,mod2=0;
	bool flag1=test(y1),flag2=test(y2);
	for(int i=1;i<m1;i++)
	{
		if(flag1)
		mod1+=run[i];
		else
		mod1+=ping[i];
	}
	mod1+=d1;
	
	for(int i=12;i>=m2;i--)
	{
		if(flag2)
		mod2+=run[i];
		else
		mod2+=ping[i];
	}
	mod2-=d2;

	int moon=0;
	for(int k=y2+1;k<y1;k++)
	if(test(2000+k))
	moon++;
	
	if(y1-y2==1)
	return mod1+mod2;
	else if(y1==y2)
	{
		return (flag1?366:365)-mod1-mod2+1; 
	}
	else
	return mod2+mod1+365*(y1-y2-1)+moon;
	
}
int main()
{
	// MM/DD/YY 第一个不能超过12，第二个不能超31，第三个不能超23；      
	// YY/MM/DD 第一个不能超过23，第二个不能超12，第三个不能超31；	
		int s1,s2,s3;
		scanf("%d/%d/%d",&s1,&s2,&s3);
		bool f1=false,f2=false;
		
		if(s1<=12&&s2<=31&&s3<=23)//满足f1初筛 
		{
			bool R=test(s3);
			if(s1==2&&R&&s2<=29)//单独讨论闰年 
			f1=true;
			else if(s2<=ping[s1])
			f1=true;
		}
		
		if(s1<=23&&s2<=12&&s3<=31)//满足f2初筛
		{
			bool R=test(s1);
			if(s2==2&&R&&s3<=29)
			f2=true;
			else if(s3<=ping[s2])
			f2=true;	
		} 
		if(f1&&!f2)
		cout<<mon[s1]<<" "<<s2<<","<<"20"<<s3<<endl;
		if(f2&&!f1)
		cout<<mon[s2]<<" "<<s3<<","<<"20"<<s1<<endl;
		if(f1&&f2)
		{
			if(s1>=s3)
			cout<<date(s1,s2,s3,s3,s1,s2)<<endl; //year,month,date	
			else 
			cout<< date(s3,s1,s2,s1,s2,s3)<<endl; 
		}
		return 0;
	
}
