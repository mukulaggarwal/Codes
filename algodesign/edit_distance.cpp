#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int lcs[10000][10000];
int main()
{
    char x[10000],y[10000];
    cin>>x>>y;
    int n=strlen(x);
    int m=strlen(y);
    int i,j;
    int costi,costd,costr;
    cout<<"enter the cost of insertion deletion and replacement\n";
    cin>>costi>>costd>>costr;
    for(i=0;i<=n;i++)
    {
        lcs[i][0]=i;
    }
    for(i=0;i<=m;i++)
    {
        lcs[0][i]=i;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
                if(x[i-1]!=y[j-1])
                {
                lcs[i][j]=min(min(costr+lcs[i-1][j-1],costi+lcs[i][j-1]),costd+lcs[i-1][j]);
                }
                else
                {
                    lcs[i][j]=min(min(lcs[i-1][j-1],costi+lcs[i][j-1]),costd+lcs[i-1][j]);
                }

        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            cout<<lcs[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"length is "<<lcs[n][m]<<endl;
    return 0;
}
