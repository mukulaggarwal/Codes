#include<stdio.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int t,n,i,a,b;
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        scanf("%d",&n);
        scanf("%d",&a);
        for(i=2;i<=n;i++)
        {
            scanf("%d",&b);
            a=gcd(a,b);
            if(a==1)
                flag=1;
        }
        if(flag==1)
            printf("%d\n",n);
        else
            printf("-1\n");
    }
    return 0;
}
