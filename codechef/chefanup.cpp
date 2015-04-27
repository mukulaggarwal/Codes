#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll t,n,k,l,i,rem;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&k,&l);
        ll a[n];
        memset(a,0,sizeof(a));
        l--;
        i=n-1;
        for(i=n-1;i>=0;i--)
        {
            rem=l%k;
            a[i]=rem;
            l=l/k;
        }

        for(i=0;i<n;i++)
        {
            a[i]+=1;
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
