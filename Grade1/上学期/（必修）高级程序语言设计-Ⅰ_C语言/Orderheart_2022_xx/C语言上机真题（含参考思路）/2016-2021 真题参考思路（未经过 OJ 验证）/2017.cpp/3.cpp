#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
char map[7][3]={"07","08","09","0A","0B","0C","0D"};
int main()
{
	int sum=0;
	char s[110];
	gets(s);
	int len=strlen(s)-1;
	for(int i=0;i<=len;i++)
	{
		if(s[i]!='\\')
			printf("%2X ",s[i]);
		else
			{
			   	int  ch=s[i+1];
				switch(ch)
				{
					case 'a':cout<<map[0]<<" ";break;
					case 'b':cout<<map[1]<<" ";break;
					case 't':cout<<map[2]<<" ";break;
					case 'n':cout<<map[3]<<" ";break;
					case 'v':cout<<map[4]<<" ";break;
					case 'f':cout<<map[5]<<" ";break;
					case 'r':cout<<map[6]<<" ";break;
				 } 
				i++;
			}
		
	}
	return 0;
}
