#include<bits/stdc++.h>
using namespace std;

int compare(int a,int b)
{
    if(a>b)
        return 1;
    else
        return -1;
}
int main()
{
    int t,n,i,j,swp=0,cmp=0;
    scanf("%d",&t);
    while(t--)
    {
        cmp=0;
        swp=0;
        scanf("%d",&n);
        int a[n+1];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<n;i++)
        {
            j=i-1;
            int key=a[i];
            while(j>=0)
            {
                cmp++;
                if(compare(a[j],key)>0)
                {
                    int temp=a[j-1];
                    a[j-1]=a[j];
                    a[j]=temp;
                    swp++;
                    j--;
                }
                else
                    break;
            }
            a[j+1]=key;
        }
        printf("%d\n",abs(cmp-swp));
    }
    return 0;
}
