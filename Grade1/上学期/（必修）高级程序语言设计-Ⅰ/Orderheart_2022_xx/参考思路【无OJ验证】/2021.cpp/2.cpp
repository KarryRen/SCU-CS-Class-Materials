#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;

int main ()
{
 	cin>>n;
 	int num;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>num;
 		int a[num];
 		for(int j=0;j<num;j++)
 		cin>>a[j];
 		sort(a,a+num);
 		if(num==1)
 		cout<<"ERROR"<<endl;
 		else
 		{
 			bool flag= true;
 		   for(int k=1;k<num;k++)
			{
				if(a[k]!=a[k-1])
					{
						  cout<<a[k]<<endl;
						  flag=false;
						  break;					
						}	
			}
			if(flag)
			cout<<"ERROR"<<endl;	
		}
	 }
    return 0;
}