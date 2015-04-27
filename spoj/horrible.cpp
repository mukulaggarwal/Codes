#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void updatest(ll *st,ll qs,ll qe,ll ss,ll se,ll index,ll value)
{
    if(qs>se||qe<ss)
        return ;
    if(ss==se&&qs<=ss&&qe>=ss)
        st[index]+=value;
    else
    {
        ll mid = ss+(se-ss)/2;
        updatest(st,qs,qe,ss,mid,2*index+1,value);
        updatest(st,qs,qe,mid+1,se,2*index+2,value);
        st[index]=st[2*index+1]+st[2*index+2];
    }
}

ll getsum(ll *st,ll qs,ll qe,ll ss,ll se,ll index)
{
    if(qs>se||qe<ss)
        return 0;
    if(qs<=ss&&qe>=se)
        return st[index];
    ll mid=ss+(se-ss)/2;
    return (getsum(st,qs,qe,ss,mid,2*index+1)+getsum(st,qs,qe,mid+1,se,2*index+2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,q,type,l,r,val,sz,x;
    //cin>>t;
    scanf("%lld",&t);
    while(t--)
    {
        //cin>>n>>q;
        scanf("%lld%lld",&n,&q);
        x=(ll)ceil(log2(n));
        sz=2*(ll)pow(2,x)-1;
        ll *st = new ll[sz+1];
         for(int i=0;i<=sz;i++)
            st[i]=0;

        while(q--)
        {
            //cin>>type>>l>>r;
            scanf("%lld%lld%lld",&type,&l,&r);
            if(type==0)
            {
                //cin>>val;
                scanf("%lld",&val);
                updatest(st,l-1,r-1,0,n-1,0,val);
            }
            else
                printf("%lld\n",getsum(st,l-1,r-1,0,n-1,0));
                //cout<<getsum(st,l-1,r-1,0,n-1,0)<<endl;
        }

       // for(int i=0;i<=sz;i++)
         //   cout<<st[i]<<" ";
        delete[] st;
    }
    return 0;
}
