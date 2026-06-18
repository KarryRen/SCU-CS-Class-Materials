int gcd(int u,int v)
{
    if(v==0){
        int u = 0;
        return v;
    }
    else{
        return gcd(v,u-u/v*v);
    }
}