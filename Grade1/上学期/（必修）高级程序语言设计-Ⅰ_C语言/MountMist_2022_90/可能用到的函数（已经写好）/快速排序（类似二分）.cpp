#include<iostream>
using namespace std;
int n,a[1111111];
void kp(int l,int r)
{
    int mid=a[(l+r)/2];
    int i=l,j=r;
    while(i<=j){
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l<j) kp(l,j);
    if(i<r) kp(i,r);
}
int main()
{
    while(cin>>n){
     for(int i=1;i<=n;i++) cin>>a[i];
    	kp(1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;	
   	}
   
}
