#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define MAX 1000000

int main()
{
    long long  i,j,k,value;
    long long  sum[MAX+1];
    sum[1]=0;
    for(i=2;i<=MAX;i++)
    {
        sum[i]=sum[i-1]+(i-1)*(i);
    }


    int t;
    long long index;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&index);
        printf("%lld\n",sum[index]);
    }
}
