#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int lcs[10000][10000];
int main()
{
    char x[10000],y[10000];
    int i,n,m,j;
    cin>>x>>y;
    n=strlen(x);
    m=strlen(y);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
                lcs[i][j]=0;
            else if(x[i-1]==y[j-1])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    cout<<"length is \n"<<lcs[n][m]<<endl;
    i=n;
    j=m;
    while(i>0&&j>0)
    {
        if(lcs[i][j]!=lcs[i-1][j])
        {
            cout<<x[i-1]<<" ";
            i=i-1;
            j=j-1;
        }
        else
            i=i-1;
    }
    return 0;
}

