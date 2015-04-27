#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define M 1000000007
long long int power(long long int n)
{
    if(n==0)
        return 26;
    if(n==1)
        return 26;
    long long int x=power(n/2);
    x=(x*x)%M;
    if(n%2)
        x=(x*26)%M;
    return x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,ans=0;
        scanf("%lld",&n);
        if(n==1)
            printf("26\n");
        else
        {
            if(n%2==0)
            {

            }
            printf("%lld\n",ans);
        }

    }
    return 0;
}
