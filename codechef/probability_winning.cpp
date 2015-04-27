#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    long long t1,t2,t3,t4,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&t1,&t2,&t3,&t4);
        printf("%lf\n",t1/(double)(t1+t2));
    }
    return 0;
}
