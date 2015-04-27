#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int r,c,i,j;
    cin>>r>>c;
    int cost[r][c];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>cost[i][j];
        }
    }

    int t[r][c];
    t[0][0]=cost[0][0];
    for(i=1;i<r;i++)
    {
        t[i][0]=t[i-1][0]+cost[i][0];
    }

    for(i=1;i<c;i++)
    {
        t[0][i]=t[0][i-1]+cost[0][i];
    }

    for(i=1;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            t[i][j]=min(min(t[i-1][j-1],t[i-1][j]),t[i][j-1])+cost[i][j];
        }
    }
    cout<<"minimum cost path is "<<t[r-1][c-1]<<endl;
    i=r-1;
    j=c-1;
    while(i>=0&&j>=0)
    {
        int temp=min(min(t[i-1][j-1],t[i-1][j]),t[i][j-1]);
        if(temp==t[i-1][j-1])
        {
            cout<<cost[i][j]<<" ";
            i=i-1;
            j=j-1;
        }
        else if(temp==t[i-1][j])
        {
            cout<<cost[i][j]<<" ";
            i=i-1;
        }
        else
        {
            cout<<cost[i][j]<<" ";
            j=j-1;
        }
    }
    cout<<cost[0][0]<<endl;
    return 0;
}
