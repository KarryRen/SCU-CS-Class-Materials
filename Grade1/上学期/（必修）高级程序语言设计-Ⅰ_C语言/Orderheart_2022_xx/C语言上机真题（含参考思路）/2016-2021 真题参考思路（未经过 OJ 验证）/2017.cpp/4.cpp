#include<iostream>
using namespace std;
int ju[101][101],juan[101][101],tmp[101][101]; 
int x,h;
void turn_90()
{	
	for(int i=1;i<=h;i++)
	for(int j=1;j<=h;j++)
		tmp[i][j]=juan[i][j];//临时拷贝一下操作前的卷积数组
	
	for(int x2=1,y1=1;x2<=h,y1<=h;x2++,y1++)
	for(int y2=1,x1=h;y2<=h,x1>=1;y2++,x1--)
		juan[x2][y2]=tmp[x1][y1];	
		
}
int Do(int a,int b)//读入矩阵数组的坐标
{
	int sum=0;
	int xx=h/2+1,yy=h/2+1;//记录卷积中心位置
	
	for(int k=1;k<=h;k++)//枚举卷积数组
	for(int l=1;l<=h;l++)
	{
		int dx=k-xx,dy=l-yy;//相对位置
		int nx=dx+a,ny=dy+b;//实际位置 
		if(nx<1||nx>x||ny<1||ny>x)
			continue;
		else
		{
			sum+= juan[k][l]*ju[nx][ny];	
		}	
	}
	return sum;
}
int main()
{
	
	cin>>x>>h;
	for(int i=1;i<=x;i++)
	for(int j=1;j<=x;j++)
		cin>>ju[i][j];
		
	for(int i=1;i<=h;i++)
	for(int j=1;j<=h;j++)
		cin>>juan[i][j];
		
	turn_90();
	turn_90();
	
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=x;j++)
			cout<<Do(i,j)<<" ";
		cout<<endl;
	}
	
	return 0;
}
