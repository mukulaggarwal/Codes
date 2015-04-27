#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int i,j,n,m;
    char x[5001],y[5001],x1[5001],y1[5001];
    scanf("%s",x1);
    scanf("%s",y1);
    //puts(x);
    //puts(y);
    n=strlen(x1);
    j=0;
    for(i=0;i<n;i++)
    {
        if(x1[i]!='a'&&x1[i]!='e'&&x1[i]!='i'&&x1[i]!='o'&&x1[i]!='u')
        {
            x[j++]=x1[i];
        }
    }
    j=0;
       for(i=0;i<n;i++)
    {
        if(y1[i]!='a'&&y1[i]!='e'&&y1[i]!='i'&&y1[i]!='o'&&y1[i]!='u')
        {
            y[j++]=y1[i];
        }
    }

    n=strlen(x);
    m=strlen(y);
    int lcs[m+1][n+1];
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
                lcs[i][j]=0;
            else if(y[i-1]==x[j-1]&&x[j-1]!='a'&&x[j-1]!='e'&&x[j-1]!='i'&&x[j-1]!='o'&&x[j-1]!='u')
                lcs[i][j]=lcs[i-1][j-1]+1;
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    printf("%d\n",lcs[m][n]);

}
