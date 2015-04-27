#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int main()
{
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    int dp[n+1][k+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(i==0||j>i)
                dp[i][j]=0;
            else if(j==0||j==i)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
}
