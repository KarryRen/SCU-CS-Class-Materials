//string 另解
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
struct node
{
	string s;
	int sum=1;
}w[100];
int main()
{
	string ch;int total=1;
	while(getline(cin,ch))
	{
		int len=ch.size()-1;
		for(int i=0;i<=len;i++)//转化小写 
			ch[i]=tolower(ch[i]);
			
		for(int i=0;i<=len;i++)//放置单词 
		{
			if(ch[i]<='z'&&ch[i]>='a')//发现可放置单词 
			{
				while(ch[i]<='z'&&ch[i]>='a')
				w[total].s+=ch[i++];
				total++;//单词数+1 
			}
		}
	}
	//选择排序遍历
	for(int i=1;i<=total-2;i++)
		for(int j=i+1;j<=total-1;j++)
		if(w[i].s==w[j].s)
		{
			w[i].sum++;w[j].sum++;
		}
	//找最大 
	int max=1;
	for(int i=1;i<=total-1;i++)
		if(w[i].sum>w[max].sum||(w[i].sum==w[max].sum&&w[i].s>w[max].s))
			max=i;
	cout<<w[max].s<<" "<<w[max].sum<<endl;
		
		return 0;
	
}





//第二次小测的计算方法
#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cstdio>
using namespace std;
struct words{
    char str[100];
    int sum=1;
};

int main(){

    struct words ch[1000];
    int m=0,max=0;
    char flag;

    while((flag=getchar())!=EOF)
    {
        if( (flag <= 'z' && flag >= 'a') || (flag <= 'Z' && flag >= 'A') )
        {
            int k=1;
            ch[m].str[0] = flag;
            while( ((flag=getchar()) <= 'z' && flag >= 'a') || (flag <= 'Z' && flag >= 'A') )
                ch[m].str[k++]=flag;
                
            ch[m].str[k]='\0';

            for (k = 0; k <= strlen(ch[m].str) - 1; k++) //变成小写
            {
                ch[m].str[k] = tolower(ch[m].str[k]);
            }
            m++;
        }
    }

    for(int i=0;i<m;i++)
        for(int j=i+1;j<1000;j++)
        {
            if(strcmp(ch[i].str,ch[j].str)==0)
            {
                ch[i].sum++;ch[j].sum++;
            }
        }

    for(int i=0;i<m;i++)//寻找出现最多次数的下标
    {
        if(ch[i].sum>ch[max].sum)
            max=i;
    }

    for(int i=0;i<m;i++)//找到字典序最大的数
    {
        if(ch[i].sum==ch[max].sum&&strcmp(ch[i].str,ch[max].str)>=0)
            max=i;
    }

    cout<<ch[max].str<<" "<<ch[max].sum<<endl;
    return 0;
}