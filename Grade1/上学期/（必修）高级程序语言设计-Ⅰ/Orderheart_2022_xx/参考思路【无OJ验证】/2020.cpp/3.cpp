#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main ()
{
    int n;
    double sum=0;
    cin>>n;int nn=n;
    for(int q=1;q<=nn;q++)
    {
        char ch[4];
        scanf("%s",ch);
        if(strcmp(ch,"n/a")==0)
        {
            n--;continue;
        }
        else
        {
            int len = strlen(ch)-1,temp=0;
            for(int j=0;j<=len;j++)
            {
                temp+=(temp*10)+(ch[j]-'0');
            }
            sum+=temp;
        }

    }
    printf("%.2lf",sum/(n*1.00));
    return 0;
}