#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
#define M 1000000007

long long int power(long long int a,long long int b)
{
    if(b==0)
        return 1;
    long long int x=power(a,b/2);
    if(b%2==0)
        return (x*x)%M;
    else
        return (((x*x)%M)*a)%M;
}

int main()
{
    long long int t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n%2!=0)
        printf("%lld\n",(power(2,(n+1)/2)+power(2,(n+1)/2)-2)%M);
        else
            printf("%lld\n",(power(2,(n/2)+1)+power(2,n/2)-2)%M);
    }
    return 0;
}
