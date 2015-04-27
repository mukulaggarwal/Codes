#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int check(long long int n)
{
    long long int i;
    while(n)
    {
        i=n%10;
        if(i==4||i==7)
            return 1;
        n=n/10;
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,i,val,counter=0,c,d;
        scanf("%lld",&n);
        for(i=1;i*i<=n;i=i++)
        {
            if(n%i==0)
            {
                c=check(i);
                d=check(n/i);
                counter+=c+d;
            }
        }
        printf("%lld\n",counter);
    }
    return 0;
}
