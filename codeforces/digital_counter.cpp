#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int n;
    int a[10]={2,7,2,3,3,4,2,5,1,2};
    scanf("%d",&n);
    printf("%d\n",a[n/10]*a[n%10]);
    return 0;
}
