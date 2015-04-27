#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int jumps[n+1];
    jumps[0]=0;
    for(i=1;i<n;i++)
    {
        jumps[i]=INT_MAX;
        for(j=0;j<i;j++)
        {
            if(j+a[j]>=i&&jumps[j]!=INT_MAX)
            {
                jumps[i]=min(jumps[i],jumps[j]+1);
                break;
            }
        }
    }

    printf("%d\n",jumps[n-1]);
    return 0;
}
