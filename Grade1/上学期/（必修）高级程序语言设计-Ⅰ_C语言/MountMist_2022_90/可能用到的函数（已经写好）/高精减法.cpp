#include<bits/stdc++.h>
using namespace std;
int a[10090]={0},b[10090]={0},c[10090]={0};
string sa,sb,tmp;
int la,lb,lc;
bool flag=false;
bool larger(string sa,string sb)
{
	 int lla=sa.size();int llb=sb.size();
	 if(lla>llb)return true;
	 if(lla<llb)return false;
	 for(int i=0;i<lla;i++)
	 {
	 	if(sa[i]>=sb[i])return true;
	 	else return false; 
	 }
}
int main()
{
	cin>>sa>>sb;
	if(!larger(sa,sb)){
		flag=true;
		tmp=sa;sa=sb;sb=tmp;
	}
	 la=sa.size();lb=sb.size();lc=max(la,lb);
	 for(int i=0;i<la;i++)a[la-i]=sa[i]-'0';
	 for(int i=0;i<lb;i++)b[lb-i]=sb[i]-'0';
	 for(int i=1;i<=lc;i++){
	 	if(a[i]<b[i])
		 {
		 	a[i+1]--;a[i]+=10;
		  } 
		  c[i]=a[i]-b[i];
	 }
 	while(c[lc]==0&&lc>1)lc--;
 	if(flag)cout<<"-";
	 for(int i=lc;i>0;i--)cout<<c[i];
return 0;
}

