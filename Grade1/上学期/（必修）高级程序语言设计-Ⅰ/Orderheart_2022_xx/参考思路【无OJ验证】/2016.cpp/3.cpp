#include<iostream>
#include<algorithm>
#include<cmath>
#include<cctype>
using namespace std;
int n;
string str,tmp,tx;
int main()
{
	getline(cin,str);
	getline(cin,tx);
	
	tmp=str;
	for(int i=0;i<str.size();i++)
	tmp[i]=tolower(str[i]);
	
	for(int i=0;i<tx.size();i++)
	tx[i]=tolower(tx[i]);
	
	int pos=tmp.find(tx);
	int len=tx.size();
	do
	{
		str=str.insert(pos+tx.size(),"*\\");
		str=str.insert(pos,"\\*");
		
		tmp=str;
		
		pos=tmp.find(tx,pos+3);
			
	}while(pos!=-1);
	
	cout<<str<<endl;
    return 0;
}
//瞿神提供，开两个标记数组，不用操作原数组
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[101];
    gets(str);
    char son[101];
    gets(son);
    int len1=strlen(str);
    int len2=strlen(son);
    int flag1[len1];
    int flag2[len1];
    for(int k=0;k<len1;k++)
    {
        flag1[k]=0;
        flag2[k]=0;
    }
    char str1[101];
    int i=0,j=0;
    for( i=0;i<len1;i++)
    {
        if(str[i]==son[j]||str[i]==son[j]-32||str[i]==son[j]+32)
        {
            int flag=1;
            for(j=1;j<len2;j++)
            {
                if(str[i+j]!=son[j]&&str[i+j]!=son[j]+32&&str[i+j]!=son[j]-32)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                flag1[i]=1;
                flag2[i+len2-1]=1;
            }
            j=0;
        }
    }
    for(i=0;i<len1;i++)
    {
        if(flag1[i]==1)
            printf("/*");
        putchar(str[i]);
        if(flag2[i]==1)
            printf("*/");
    }
    return 0;
}