
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main ()
{
    int n;cin>>n;
    int temp=n;
    double x,sum=0;
    while(temp--)
    {
        cin>>x;
        sum+=x;
    }
    printf("%.2lf\n",sum/n);
    return 0;
}