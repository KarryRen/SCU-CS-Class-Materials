//唯神提供，由正则表达式读入数据，yyds！！
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int n;

struct player{
	string str;
	int sum=0;//总积分
	int sum1=0;//净得分

};
bool cmp(struct player a,struct player b)
{
	if(a.sum!=b.sum)
	return a.sum>b.sum;
	else
	{
		if(a.sum1!=b.sum1)
		return a.sum1>b.sum1;
		else
			return a.str>b.str; 
	}
}

int main(){
	cin>>n;
	getchar();
	struct player s[n+1];
  	for(int i=1;i<=n;i++)
  	{
  		getline(cin,s[i].str);
  	}
  	for(int r=1;r<=n*(n-1)/2;r++)
  	{
  		char name1[20],name2[20];
  		int grade1,grade2;
  		scanf("%[^-]%*c%[^:]%*c%d%d",name1,name2,&grade1,&grade2);
  		getchar();
  		grade2=abs(grade2);
		
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(s[i].str==name1&&s[j].str==name2)
		{
		  	s[i].sum1+=grade1-grade2;
		  	s[j].sum1+=grade2-grade1;

			if(grade1>grade2)
			s[i].sum+=3;
			else if(grade1==grade2)
			{
				s[i].sum++;s[j].sum++;
			}
			else if(grade1<grade2)
			s[j].sum+=3;
		}
	}

	sort(s+1,s+n+1,cmp);
	
	cout<<s[1].str;
	int total=1; 
	for(int i=2;i<=n;i++)
	{
		if(total==n/2)
		break;
		if(s[i].sum==s[i-1].sum&&s[i].sum1==s[i-1].sum1)
		{
			cout<<" "<<s[i].str;
			total++;
		}
		else
		{
			cout<<endl<<s[i].str;
			total++;
	    }
	}
	
    return 0;
}



//该方法读取数据，存在无法读取队伍名，若乱序则会出现混乱的问题
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int n,tmp=0;

struct player{
	string str;
	int sum=0;//总积分
	int sum1=0;//净得分

};
bool cmp(struct player a,struct player b)
{
	if(a.sum!=b.sum)
	return a.sum>b.sum;
	else
	{
		if(a.sum1!=b.sum1)
		return a.sum1>b.sum1;
		else
			return a.str>b.str; 
	}
}

int main(){
	cin>>n;
	getchar();
	struct player s[n+1];
  	for(int i=1;i<=n;i++)
  	{
  		getline(cin,s[i].str);
  	}
  	getchar();
  	for(int i=1;i<=n-1;i++)
  	for(int j=i+1;j<=n;j++)
  	{
  		string ch,g1,g2;
          getline(cin,ch);
          int pos1=ch.find('-');
          int pos2=ch.find(':');
          int pos3=ch.find('-',pos1+1);
          int len=ch.size()-1;

          int grade1,grade2;
          for(int w=pos2;w<=pos3;w++)
          {
              if(ch[w]<='9'&&ch[w]>='0')
                  g1+=ch[w];
          }
          for(int w=pos3;w<=len;w++)
          {
              if(ch[w]<='9'&&ch[w]>='0')
                  g2+=ch[w];
          }

          grade1=atoi(g1.c_str());
          grade2=atoi(g2.c_str());

		  s[i].sum1+=grade1-grade2;
		  s[j].sum1+=grade2-grade1;

		if(grade1>grade2)
		s[i].sum+=3;
		else if(grade1==grade2)
		{
			s[i].sum++;s[j].sum++;
		}
		else if(grade1<grade2)
		s[j].sum++;
	}

	sort(s+1,s+n+1,cmp);
	
	cout<<s[1].str;
	
	for(int i=2;i<=n;i++)
	{
		if(s[i].sum==s[i-1].sum&&s[i].sum1==s[i-1].sum1)
		cout<<" "<<s[i].str;
		else
		cout<<endl<<s[i].str;
	}
	
    return 0;
}