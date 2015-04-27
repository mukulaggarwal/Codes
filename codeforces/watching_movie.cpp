#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,l,r,result=0,length=1,i;
    scanf("%lld%lld",&n,&x);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&l,&r);
        while(length+x<=l)
            length=length+x;
        result+=r+1-length;
        length=r+1;
    }
    printf("%lld\n",result);
    return 0;
}
