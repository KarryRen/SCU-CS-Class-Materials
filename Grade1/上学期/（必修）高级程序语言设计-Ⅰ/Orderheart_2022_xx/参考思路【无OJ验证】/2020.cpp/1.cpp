#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main ()
{
    int T;
    cin>>T;
    while(T--)
    {
        bool flag=true;
        string s;
        cin>>s;
        if(s=="SCU")
            cout<<"YES"<<endl;
        else
        {
            int x=s.find("SCU");
            if(x==-1)
                cout<<"NO"<<endl;
            else
            {
                int l=x-1,r=x+4;
                for(int i=0,j=s.size()-1;i<=l,j>=r;i++,j--)
                {
                    if(s[i]!='A'||s[j]!='A')
                        flag=false;
                }
                if(flag)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}