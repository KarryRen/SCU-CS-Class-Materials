#include<iostream>
#include<cmath>
using namespace std;
int n;

int main ()
{
 	cin>>n;
	double num;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		if(num<0)
		cout<<"ERROR"<<endl;
		else
		printf("%.2lf\n",sqrt(num));
	}
	
    return 0;
}