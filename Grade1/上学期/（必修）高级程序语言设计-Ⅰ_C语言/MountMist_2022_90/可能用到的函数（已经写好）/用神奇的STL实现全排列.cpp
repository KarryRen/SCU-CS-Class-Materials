#include<bits/stdc++.h>
using namespace std;
int n,a[666],b[666],s=1;
long long num;
long long js(int n)
{
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
}
int main()
{
	cin>>n;
	num=js(n);
	cout<<num<<endl;
    for(int i=0;i<n;i++)
        b[i]=i+1;   
   	for(int i=0;i<n;i++)cout<<b[i]<<" ";
	cout<<endl; 
    while(s<num)    
    {
        next_permutation(b,b+n);   
     	for(int i=0;i<n;i++)cout<<b[i]<<" ";
	    s++;    
	    cout<<endl;
    }
    return 0;
}
 
