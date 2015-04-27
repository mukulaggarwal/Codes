#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        int k,ans,result;
        scanf("%d%d",&n,&k);
        int a[n+1];
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int dp[n+1][1024];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=1023;j++)
            {
                dp[i][j]=0;
            }
        }
        dp[0][0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=1023;j++)
            {
                dp[i][j]=dp[i-1][j]|dp[i-1][j^a[i]];
            }
        }
        result=0;
        for(i=0;i<=1023;i++)
        {
            ans=dp[n][i]*(i^k);
            //cout<<"i is "<<i<<" "<<dp[n][i]<<endl;
            if(ans>result)
                result=ans;
        }
        printf("%d\n",result);
    }
}
