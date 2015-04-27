#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

typedef int ll;

ll build(ll arr[],ll *st,ll ss,ll se,ll index)
{
    if(ss==se)
    {
        st[index]=arr[ss];
        return st[index];
    }
    ll mid=ss+(se-ss)/2;
    st[index]=max(max(build(arr,st,ss,mid,2*index+1)+ build(arr,st,mid+1,se,2*index+2),st[2*index+1]),st[2*index+2]);
    return st[index];
}

ll query(ll *st,ll qs,ll qe,ll ss,ll se,ll index)
{
      if(qs<=ss&&qe>=se)
         return st[index];

    if(qs>se||qe<ss)
        return INT_MIN;

    ll mid=ss+(se-ss)/2;
   // cout<<query(st,qs,qe,ss,mid,2*index+1)<<" "<<query(st,qs,qe,mid+1,se,2*index+2)<<endl;
      return max(query(st,qs,qe,ss,mid,2*index+1),query(st,qs,qe,mid+1,se,2*index+2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n,i,q,j;
    scanf("%d",&n);
    ll arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    ll x=(ll)ceil(log2(n));
    ll sz=2*(ll)pow(2,x)-1;
    ll *st = new ll[sz];

   build(arr,st,0,n-1,0);
    scanf("%d",&q);
    ll l,r;
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&l,&r);
        //cout<<query(st,l-1,r-1,0,n-1,0)<<endl;
        printf("%d\n",query(st,l-1,r-1,0,n-1,0));
    }
}
