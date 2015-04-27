#include<stdio.h>
int K[1000][1000];

int max(int a, int b) { return (a > b)? a : b; }
int min(int a, int b) { return (a < b)? a : b; }



int fun(int *d,int *f,int m,int n)

{

   int dp[501][1001],i,j,res=0;
   dp[0][0] =0;
   for (i = 1; i <= 2*m; i++)
      dp[0][i] = 10000;
   for (i = 1; i <= n; i++)
   {
       for(j = 1; j <= 2*m; j++)
       {
        dp[i][j] = dp[i-1][j];
        if(f[i-1] <= j)
         dp[i][j] = min(dp[i-1][j],1 + dp[i][j-f[i-1]]);
        }
   }

    for (i = 0; i < n; i++)
     res = res + dp[n][2*d[i]];
    return res;


}



int main()
{
    int T,n,d[1000],f[1000],i,ans=0,m=0;
    scanf("%d",&T);

    while(T>0)
    {
                  scanf("%d",&n);
                  for(i=0;i<n;i++)
                   {
                                  scanf("%d",&d[i]);
                                  m = max(m,d[i]);
                   }
                  for(i=0;i<n;i++)
                     scanf("%d",&f[i]);

                  ans = fun(d,f,m,n);
                   printf("%d\n",ans);





    T--;

    }
    return(0);
}
