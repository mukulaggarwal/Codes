#include<bits/stdc++.h>
using namespace std;

set<long long> prime;
#define MOD 1000000007
long long mulmod(long long a,long long b)
 {if(b==0)
   return 1;
   if(b==1)
    return a;
   long long x=mulmod(a,b/2);
   x=(x*x)%MOD;
   if(b%2)
     x=(x*a)%MOD;
    return x;
 }

 long long gcd(long long a,long long b)
 {
     if(b==0)
        return a;
     return gcd(b,a%b);
 }

int main()
{
    long long t,n,i,sum,flag,k,j;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        prime.clear();
        sum=1;
        if(k>1)
        {
        for(i=2;i<=sqrt(n);i++)
        {
            long long x=gcd(i,n);
            if(x==1)
            {
                sum=(sum+mulmod(i,k)%MOD)%MOD;
            }
            x=gcd(n/i,n);
            if(x==1)
            {
                sum=(sum+mulmod(i,k)%MOD)%MOD;
            }
        }
        printf("%lld\n",sum);
        }
        else
        {
            if(k==0)
            {
                sum=n%MOD;
            }
            else
                {
                    long long p1=n;
                    long long p2=n+1;
                    if(p1%2==0)
                        p1=p1/2;
                    else
                        p2=p2/2;
                    sum=((p1%MOD)*(p2%MOD))%MOD;
                }
                for(i=2;i<=sqrt(n);i++)
                {
                    if(prime.find(i)!=prime.end())
                        prime.erase(prime.find(i));
                    else if(gcd(n,i)!=1)
                        sum=(sum%MOD-i%MOD+MOD)%MOD;
                    for(j=i*i;j<=n;j=j+i)
                    {
                        if(gcd(n,j)!=1)
                        {
                            sum=(sum%MOD-j%MOD+MOD)%MOD;
                            prime.insert(j);
                        }

                    }
                }
                printf("%lld\n",sum);

        }
    }
}
