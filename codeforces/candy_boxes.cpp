#include<cstdio>
#include<iostream>
using namespace std;

#define Max 1000000
#define Min 1
int main()
{
    double n,a,b,c,d,i;
    scanf("%lf",&n);
    if(n==0)
    {
        printf("YES\n");
        printf("1\n");
        printf("1\n");
        printf("3\n");
        printf("3\n");
    }
    else if(n==1)
    {
        scanf("%lf",&a);
        if(2*a<=Max&&3*a<=Max)
        {
            printf("YES\n");
            printf("%0.0lf\n",2*a);
            printf("%0.0lf\n",2*a);
            printf("%0.0lf\n",3*a);
        }
        else
            printf("NO\n");
    }
    else if(n==2)
    {
        scanf("%lf%lf",&a,&b);
        if(3*a<=Max&&4*a-b>=Min&&4*a-b<=Max&&4*a-b<=3*a)
        {
            printf("YES\n");
            printf("%0.0lf\n",4*a-b);
            printf("%0.0lf\n",3*a);
        }
        else
            printf("NO\n");
    }
    else if(n==3)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        if(b+c-a==(2*a+b+c)/2&&b+c-a==(5*a+b+c)/3&&b+c-a>=Min&&b+c-a<=Max&&b+c-a>=c)
        {
            printf("Yes\n");
            printf("%0.0lf",b+c-a);
        }
        else
            printf("NO\n");
    }
    else
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if((a+b+c+d)/4==(b+c)/2&&(b+c)/2==d-a)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
