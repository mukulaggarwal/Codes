#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int m,s,i=0,n,zero=0,nonzero=0;
scanf("%d%d",&m,&s);
int ans[m+1];
if(s==0)
{
    printf("-1 -1\n");
}
else if(m*9<s)
{
    printf("-1 -1\n");
}
else
{
    i=0;
    n=m;
    while(m>0)
    {
        if(s-9>=0)
        {
            ans[i++]=9;
            s=s-9;
            nonzero++;
            m--;
        }

        else
        {
            if(max(0,s)==0)
                zero++;
            else
                nonzero++;
            ans[i++]=max(0,s);
            s=s-9;
            m--;
        }
    }

        int maximum[n+1];
        for(i=n-1;i>=0;i--)
            maximum[i]=ans[i];
        if(nonzero+9<=zero)
        {
        if(zero>=1)
        {
            int counter=0;
            for(i=n-1;i>=0;i--)
            {
                if(ans[i]==0)
                {
                    printf("1");
                    counter++;
                }
                else
                {
                    if(ans[i]-counter>=0)
                    {
                        printf("%d",ans[i]-counter);
                        counter=0;
                    }
                    else
                    {
                        printf("1");
                        counter++;
                    }
                }
            }
            printf(" ");
            for(i=0;i<n;i++)
                printf("%d",maximum[i]);
            printf("\n");

        }
        }
        else if(zero>=1)
        {
            for(i=0;i<n;i++)
                printf("%d",ans[i]);
            printf(" ");
            for(i=0;i<n;i++)
                printf("%d",ans[i]);
        }
        else
        {
            for(i=n-1;i>=0;i--)
                printf("%d",ans[i]);
            printf(" ");
            for(i=0;i<n;i++)
                printf("%d",ans[i]);
            printf("\n");
        }
    }
return 0;
}
