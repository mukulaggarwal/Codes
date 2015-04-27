#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long int a,b,i,first,count=0;
    scanf("%lld%lld",&a,&b);
    if(a<b)
        printf("0\n");
    else if(a==b)
        printf("infinity\n");
    else
    {
        first=a-b;
        long long int temp=first;
        while(temp<=ceil(sqrt(first)))
        {
            if(a%temp==b)
                count++;
            temp++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
