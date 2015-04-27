#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int hy,ay,dy,hm,am,dm,h,a,d,ans,coins;
    scanf("%d%d%d",&hy,&ay,&dy);
    scanf("%d%d%d",&hm,&am,&dm);
    scanf("%d%d%d",&h,&a,&d);
    ans=hy+ay+dy-hm-am-dm;
    if(ans>0)
        printf("0\n");
    else
    {
        ans=-ans;
        printf("%d",ans*min(min(h,a),d));
    }
    return 0;
}
