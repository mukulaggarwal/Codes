#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    int i,j,r,c,maximum,maxi,maxj;
    cin>>r>>c;
    int a[r][c],s[r][c];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        cin>>a[i][j];

    for(i=0;i<r;i++)
        s[i][0]=a[i][0];
    for(i=0;i<c;i++)
        s[0][i]=a[0][i];

    for(i=1;i<r;i++)
        for(j=1;j<c;j++)
            {
                if(a[i][j]!=0)
                s[i][j]=min(min(s[i-1][j],s[i][j-1]),s[i-1][j-1])+1;
                else
                    s[i][j]=0;
            }
    maximum=s[0][0];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(maximum<s[i][j])
            {
                maximum=s[i][j];
                maxi=i;
                maxj=j;
            }
        }
    }

    for(i=maxi;i>maxi-maximum;i--)
    {
        for(j=maxj;j>maxj-maximum;j--)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
