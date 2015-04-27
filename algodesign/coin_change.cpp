#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,m,i,j;
    scanf("%d",&n);
    scanf("%d",&m);
    int coins[m+1];
    for(i=1;i<=m;i++)
    {
        scanf("%d",&coins[i]);
    }
    int dp[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0)
                dp[i][j]=1;
            else if(j==0)
                dp[i][j]=0;
            else if(coins[j]>i)
                dp[i][j]=dp[i][j-1];
            else
                dp[i][j]=dp[i-coins[j]][j]+dp[i][j-1];
        }
    }

    printf("%d\n",dp[n][m]);
    return 0;
}
