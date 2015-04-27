#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int n,l,i,j,k,count=0;
    scanf("%d%d",&n,&l);
    int a[n+1];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(n<=2)
        printf("0\n");
    else
    {
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(a[i]*a[j]*a[k]<=l)
                        count++;
                }
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
