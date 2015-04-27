#include<cstdio>
#include<climits>
#include<iostream>
using namespace std;

int main()
{
    int n,k,i,j,x;
    cin>>n>>k;
    int eggs[n+1][k+1];
    for(i=1;i<=n;i++)
    {
        eggs[i][0]=0;
        eggs[i][1]=1;
    }

    for(i=1;i<=k;i++)
    {
        eggs[1][i]=i;
    }

    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            eggs[i][j]=INT_MAX;
            for(x=1;x<=j;x++)
            {
                eggs[i][j]=min(max(eggs[i-1][x-1],eggs[i][j-x])+1,eggs[i][j]);
            }
        }
    }

    cout<<eggs[n][k]<<endl;
    return 0;
}
