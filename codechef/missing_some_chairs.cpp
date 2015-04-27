#include<cstdio>
#include<iostream>
using namespace std;
#define M 1000000007

long long int power(long long int a,long long int b)
{
    if(b==0)
        return 1;
    long long int temp=power(a,b/2);
    if(b%2==0)
        return ((temp*temp)%M);
    else
        return ((((a*temp)%M)*temp)%M);
}

int main()
{
    long long int n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",power(2,n)-1);
    }
    return 0;
}
