#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
    vector<long long int> a,b,c;
    vector<long long int>::iterator up1,up2;
    long long int i,j,n,m,val,diff=0,ans=0;
    long long int p,q;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&val);
        a.push_back(val);
        c.push_back(val);
    }
    scanf("%lld",&m);
    for(j=0;j<m;j++)
    {
        scanf("%lld",&val);
        b.push_back(val);
        c.push_back(val);
    }
    sort(c.begin(),c.end());
    if(a[n-1]==1)
    {
        printf("%lld:%lld\n",2*n,2*m);
    }
    else
    for(i=0;i<n+m;i++)
    {
        long long int d=c[i];
        //cout<<d<<endl;
        up1=upper_bound(a.begin(),a.end(),d);
        up2=upper_bound(b.begin(),b.end(),d);
        //cout<<up1-a.begin()<<" "<<up2-b.begin()<<endl;
        diff=((up1-a.begin())-(up2-b.begin()))*3+((a.end()-up1)-(b.end()-up2))*2;
        if(diff>=ans||i==0)
        {
            p=(up1-a.begin())*3+(a.end()-up1)*2;
            q=(up2-b.begin())*3+(b.end()-up2)*2;
            ans=diff;
        }
    }
    printf("%lld:%lld\n",p,q);
    return 0;

}
