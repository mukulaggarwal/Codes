#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int w[n+1],a[n+1];
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    a[0]=0;
    a[1]=w[1];
    for(i=2;i<=n;i++)
    {
        if(a[i-1]>a[i-2]+w[i])
            a[i]=a[i-1];
        else
            a[i]=a[i-2]+w[i];
    }
    printf("%d\n",a[n]);
    int s[n],j=0;
    i=n;
    while(i>=1)
    {
        if(a[i-1]>=a[i-2]+w[i])
            i=i-1;
        else
        {
            s[j++]=w[i];
            i=i-2;
        }
    }
    for(i=0;i<j;i++)
        printf("%d ",s[i]);
    return 0;
}
