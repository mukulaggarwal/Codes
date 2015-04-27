#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,travel,j;
    scanf("%d",&t);
    while(t--)
    {
        int maximum_size=0;
        scanf("%d",&n);
        int h[n],c[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
            maximum_size=max(maximum_size,h[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
        }
        maximum_size=2*maximum_size;
        int dp[501][1001]={0};
        dp[0][0]=0;
        for(j=1;j<=maximum_size;j++)
            dp[0][j]=INT_MAX;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=maximum_size;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(c[i-1]<=j)
                {
                    dp[i][j]=min(dp[i][j-c[i-1]]+1,dp[i-1][j]);
                }
            }
        }

        /*cout<<"dp is "<<endl;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=maximum_size;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        travel=0;
        for(i=0;i<n;i++)
        {
            travel+=dp[n][2*h[i]];
        }
        printf("%d\n",travel);
    }
    return 0;
}
