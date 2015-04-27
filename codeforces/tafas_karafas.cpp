#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long l,r,i,low,high,t,m,a,b,n;
    scanf("%lld%lld%lld",&a,&b,&n);
    while(n--)
    {
        scanf("%lld%lld%lld",&l,&t,&m);
        low=l;
        high=1000000;
        if(a+(low-1)*b>t)
        {
            printf("-1\n");
            continue;
        }
        long long sum=0;
        while(low<high)
        {
            long long mid=(low+high+1)/2;
            sum=((2*a + b*(mid+l-2))*(mid-l+1))/2;
            long long ma=a+(mid-1)*b;
            if(sum<=min(mid-l+1,m)*t&&ma<=t)
            {
                low=mid;
            }
            else
            {
                high=mid-1;
            }
        }
        printf("%lld\n",low);
    }
    return 0;
}
