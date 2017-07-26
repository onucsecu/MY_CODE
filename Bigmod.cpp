#include<bits/stdc++.h>
using namespace std;
long long multiply(long long b, long long p,long long mod)
{
    long long ans=0;
    b=b%mod;
    while(p!=0){
        if(p%2==1)
            ans=(ans+b)%mod;
        b=(b+b)%mod;
        p=p/2;
    }
    return ans;
}
long long bigmod(long long b,long long p,long long mod)
{
    long long ans=1;
    b=b%mod;
    while(p!=0){
         if(p%2==1)
            ans=multiply(ans,b,mod);
         b=multiply(b,b,mod);
         p=p/2;
    }
    return ans;
}
int main()
{
    int tc,t=0;
    scanf("%d",&tc);
    while(t<tc){
            t++;
        long long b,p,mod;
        cin>>b>>p>>mod;

        long long ans;
        ans=bigmod(b,p,mod);
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
