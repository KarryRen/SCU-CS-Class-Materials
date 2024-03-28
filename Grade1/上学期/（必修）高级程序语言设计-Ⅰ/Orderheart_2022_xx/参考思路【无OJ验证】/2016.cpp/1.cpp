#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
bool flag=false;

int main()
{
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]%3==0)
		{
			flag=true;
			cout<<a[i]<<endl;
			break;
		}
	}
	if(!flag)
		cout<<"Null"<<endl;
    return 0;
}