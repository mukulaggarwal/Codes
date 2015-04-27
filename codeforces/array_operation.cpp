#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    long long int n,m,i,j,common,ans=0;
    scanf("%lld%lld",&n,&m);
    long long int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long int l,r;
    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&l,&r);
        common=gcd(a[l-1],a[r-1]);
        //cout<<common<<endl;
        for(j=2;j<=common;j++)
        {
            if(common%j==0)
            {
                a[l-1]=a[l-1]/j;
                a[r-1]=a[r-1]/j;
                ans++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
