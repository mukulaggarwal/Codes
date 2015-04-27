#include<stdio.h>
#include<limits.h>
int main()
{
    int n,i,j,min;
    scanf("%d",&n);
    int val[n+1],p[n+1];
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
        val[1]=0;
        val[0]=0;
    for(i=2;i<=n+1;i++)
    {
        min=INT_MIN;
        for(j=1;j<i;j++)
        {
            if(min<p[j]+val[i-j])
                min=p[j]+val[i-j];
        }
        val[i]=min;
    }
    printf("%d\n",val[n+1]);
}
