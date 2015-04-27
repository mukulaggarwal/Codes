#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long a,b,temp,ships=0;
    scanf("%lld%lld",&a,&b);
        if(a<b)
        {
            temp=a;
            a=b;
            b=temp;
        }
    while(1)
    {
        if(a==1||b==1)
        {
            ships+=a>b?a:b;
            break;
        }
        if(a/b>=1)
        {
            ships+=a/b;
            a=a%b;
            if(a<b)
            {
            temp=a;
            a=b;
            b=temp;
            }
        }

        if(a<=0||b<=0)
            break;
    }
    printf("%lld\n",ships);
    return 0;
}
