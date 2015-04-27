#include<stdio.h>
int main()
{
    int n,W,i,j,k;
    scanf("%d%d",&n,&W);
    int a[n+1][W+1];
    int p[n],w[n];
    for(i=1;i<=n;i++)
        scanf("%d%d",&p[i],&w[i]);

    for(i=0;i<=n;i++)   //making ist column 0
        a[i][0]=0;
    for(i=0;i<=W;i++)   //making ist row 0
        a[0][i]=0;

    for(i=1;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(j>=w[i])
            {
                if(p[i]+a[i-1][j-w[i]]>a[i-1][j])
                    a[i][j]=p[i]+a[i-1][j-w[i]];
                else
                    a[i][j]=a[i-1][j];
            }
            else
                a[i][j]=a[i-1][j];
        }
    }
    printf("%d\n",a[n][W]);

    i=n;
    j=W;
    k=0;
    int result[n];
    while(i,j>0)
    {
        if(a[i][j]!=a[i-1][j])
        {
            result[k++]=i;
            j=j-w[i];
            i=i-1;
        }
        else
            i--;
    }
    for(i=0;i<k;i++)
        printf("%d ",result[i]);
    return 0;
}
