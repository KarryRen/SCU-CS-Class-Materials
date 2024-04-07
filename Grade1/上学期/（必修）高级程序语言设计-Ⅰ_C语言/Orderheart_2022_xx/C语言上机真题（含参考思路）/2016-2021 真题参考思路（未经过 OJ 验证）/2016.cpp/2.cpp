#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
bool check(string x)
{	
	int sum=0,len=x.size()-1;
	if(len==0)
	return false;
	for(int i=0;i<=len;i++,len--)
	if(x[i]!=x[len])
	sum++;
	
	if(sum==1)
	return true;
	else
	return false;
}
int main()
{
	cin>>n;
	while(n--)
	{
		string num;
		cin>>num;
		if(check(num))
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
    return 0;
}