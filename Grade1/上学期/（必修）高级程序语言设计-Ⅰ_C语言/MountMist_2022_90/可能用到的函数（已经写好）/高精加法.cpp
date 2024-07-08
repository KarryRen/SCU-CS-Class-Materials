#include<bits/stdc++.h>
using namespace std;
int a[505]={0},b[505]={0},c[510]={0};
string sa,sb;
int la,lb,lc;
int main()
{
	 cin>>sa>>sb;
	 la=sa.size();lb=sb.size();lc=max(la,lb)+1;
	 for(int i=0;i<la;i++)a[la-i]=sa[i]-'0';
	 for(int i=0;i<lb;i++)b[lb-i]=sb[i]-'0';
	 for(int i=1;i<=lc;i++)
	 {
	 	c[i]+=a[i]+b[i];//先把加数的两位相加得和本位应有数值（由于是+=所以已经考虑了前置的进位）
	 	c[i+1]=c[i]/10;//除以10考虑进位，如12/10=1，作为下一个数位的初始值
	 	c[i]%=10;		//本位去除进位值之后剩下的值，即本位应该显示的值，如12%10=2
	 }
	 if(c[lc]==0&&lc>0)lc--;
	 for(int i=lc;i>0;i--)cout<<c[i];
	
return 0;
}

