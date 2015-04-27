#include<cstdio>
#include<iostream>
using namespace std;
int a[251][251];
int main()
{
    int n,m,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
                }
            }
        }
    }

    int s,g,d;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d%d",&s,&g,&d);
        printf("%d %d\n",a[s][g]+a[g][d],a[s][g]+a[g][d]-a[s][d]);
    }
    return 0;
}
