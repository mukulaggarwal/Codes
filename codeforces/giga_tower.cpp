#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;


int check(long long int n)
{
    long long int temp;
    while(n)
    {
        temp=n%10;
        if(temp==8)
            return 1;
        n=n/10;
    }
    return 0;
}

int main()
{
    long long int n,c1=1;
    scanf("%lld",&n);
    n++;
    while(1)
    {
        if(check(n))
        {
            printf("%lld\n",c1);
            break;
        }
        else if(n%10==0)
        {
            printf("%lld",c1+8);
            break;
        }
        else
        {
            n++;
            c1++;
        }
    }

    return 0;
}
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;


int check(long long int n)
{
    long long int temp;
    while(n)
    {
        temp=n%10;
        if(temp==8)
            return 1;
        n=n/10;
    }
    return 0;
}

int main()
{
    long long int n,c1=1;
    scanf("%lld",&n);
    n++;
    while(1)
    {
        if(check(n))
        {
            printf("%lld\n",c1);
            break;
        }
        else if(n%10==0)
        {
            printf("%lld",c1+8);
            break;
        }
        else
        {
            n++;
            c1++;
        }
    }

    return 0;
}
