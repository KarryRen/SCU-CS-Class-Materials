#include<bits/stdc++.h>
using namespace std;
int a[555][555],b[555][555];
int cnt=1;
int x,y,z,r;
//此题可作为矩阵顺逆时针旋转的模板 
void shun(int x,int y,int r)
//如果是顺时针，则旋转后矩阵的第1行是旋转前矩阵的第1列倒着数 
{
	int p=x+r;
	int q=y-r;
	for(int i=x-r;i<=x+r;i++){
		for(int j=y-r;j<=y+r;j++){
				b[i][j]=a[i][j];
			}
	}
	for(int i=x-r;i<=x+r;i++){
		for(int j=y-r;j<=y+r;j++){
			a[i][j]=b[p][q];p--;		
		}
		p=x+r;q++;
	}
	return;
}
void ni(int x,int y,int r)
//如果是逆时针，旋转后矩阵的第1行是旋转前矩阵的最后一列正着数 
{
	int p=x-r;
	int q=y+r;
	for(int i=x-r;i<=x+r;i++){
		for(int j=y-r;j<=y+r;j++){
				b[i][j]=a[i][j];
			}
	}
	for(int i=x-r;i<=x+r;i++){
		for(int j=y-r;j<=y+r;j++){
			a[i][j]=b[p][q];p++;		
		}
		p=x-r;q--;
	}
	return;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=cnt;cnt++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>r>>z;
		if(z==0)shun(x,y,r);
		if(z==1)ni(x,y,r);
	 } 
	for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		cout<<a[i][j]<<" ";
	}
	cout<<endl;
	}

return 0;
}

