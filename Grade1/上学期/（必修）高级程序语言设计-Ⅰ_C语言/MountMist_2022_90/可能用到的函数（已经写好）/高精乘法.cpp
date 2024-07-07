#include<bits/stdc++.h>
using namespace std;
string sa,sb; 
int a[2023],b[2023],c[4046];
int la,lb,lc;
int main()
{
	cin>>sa>>sb;
	la=sa.size();lb=sb.size();lc=la+lb;
	for(int i=0;i<la;i++)a[la-i]=sa[i]-'0';
	for(int i=0;i<lb;i++)b[lb-i]=sb[i]-'0';
	for(int i=1;i<=la;i++)
	{
		for(int j=1;j<=lb;j++)
		{
			c[i+j-1]+=a[i]*b[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	}
	while(c[lc]==0&&lc>1)lc--;
	for(int i=lc;i>0;i--)cout<<c[i];	

return 0;
}

