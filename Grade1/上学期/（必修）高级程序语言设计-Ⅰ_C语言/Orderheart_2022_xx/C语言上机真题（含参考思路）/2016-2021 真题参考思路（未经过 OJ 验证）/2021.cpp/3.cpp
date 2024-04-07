
//唯神另解：
#include<iostream>
using namespace std;
int main()
{
	int k;cin>>k;
	while(k--){
		int x;cin>>x;
		for(int i=2;i<10000;i++)
		{
			int n;int flag=0;
			for(n=2;n*n<i;n++){
				if(i%n==0)
				{
					flag=1;
					break;
				}
			}
			if(flag)continue;
			if(x%i==0)//如果满足分解条件
			{
				while(x%i==0)//继续尝试分解i直到不能分解为止
				{
					cout<<i;
					x/=i;
					if(x!=1)cout<<"*";
					else cout<<endl;//x==1，分解完毕，回车
				}
			}
		}
	}
}


#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#define N 10000
using namespace std;
int k,x;
bool map[N+1];

int main ()
{
	//埃氏素数生成表 
	memset(map,true,sizeof(map));
	map[1]=false;
	for(int i=2;i<=sqrt(N);i++)
	{
		if(map[i])
		for(int z=2;z*i<=N;z++)
		map[z*i]=false;
	}
	
	
 	cin>>k;
 	for(int m=1;m<=k;m++)
 	{
 		cin>>x;
 		int temp=x;int ans[100],sum=0;
 		
 		for(int j=2;j<=x;j++)
 		{
 			if(map[j]&&temp%j==0)
 			{
 				while(temp%j==0)
 				{
 					ans[++sum]=j;
 					temp/=j;
				 }
			 }
			 if(map[temp]) //已经分解到只剩质数 
			 {
			 	ans[++sum]=temp;
			 	break;
			 }
		 }
		 
		  if(sum==1)
			 cout<<ans[1]<<endl;
			 else
			 {
			 	cout<<ans[1];
			 	for(int a=2;a<=sum;a++)
			 	cout<<"*"<<ans[a];
			 	cout<<endl;
	 	  } 
	 }
    return 0;
}

