#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long temp,n,rev,digits;
    scanf("%lld",&n);
    digits=0;
    temp=n;
    rev=0;
    if(n==4)
        printf("1\n");
    else if(n==7)
        printf("2\n");
    else
    {
    while(n)
    {
        digits++;
        rev=rev*10+n%10;
        n=n/10;
    }
    long long curr=0;
    long long ans=2*(pow(2,digits-1)-1);
    ans++;
    while(rev)
    {
        curr=rev%10;
        if(curr==7)
        {
            ans+=pow(2,digits-1);
        }
        digits--;
        rev=rev/10;
    }
    printf("%lld\n",ans);
    }
    return 0;
}
