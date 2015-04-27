#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,c,l,i,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int power[101]={0};
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&c,&l);
            power[l]+=c;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&c,&l);
            power[l]=power[l]-c;
        }
        ans=0;
        for(i=0;i<101;i++)
        {
            if(power[i]<0)
            ans+=abs(power[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
