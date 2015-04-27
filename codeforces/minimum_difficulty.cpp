#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n,i,j,m;
    scanf("%d",&n);
    int a[n+1];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=INT_MAX;
    int maximum=INT_MIN;
    for(i=1;i<n-1;i++)
    {
        maximum=INT_MIN;
        for(j=0;j<n-1;j++)
        {
            if(j!=i)
            {
                if(j+1!=i)
                {
                    m=a[j+1]-a[j];
                    if(maximum<m)
                        maximum=m;
                }
                    else
                    {
                        m=a[j+2]-a[j];
                        if(maximum<m)
                            maximum=m;
                    }
                }

            }
            if(ans>maximum)
            ans=maximum;
        }

    printf("%d\n",ans);
    return 0;
}
