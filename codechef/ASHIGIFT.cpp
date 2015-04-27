#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair< ll, pair<ll,ll> > pairs;

vector<pairs> pos;


int possible(ll frnd)
{
    ll i;
    for(i=0;i<pos.size();i++)
    {
        if(pos[i].second.second==-1)
        {
            if(frnd<=pos[i].second.first)
                return 0;
            frnd=frnd-pos[i].second.first;
        }
        else
        {
            if(frnd>=pos[i].second.first)
            {
                frnd+=pos[i].second.second;
            }
        }
    }
    if(frnd>0)
        return 1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t,X,C,x,y,p,q,r,i,ans,mid,low,high,B,total;
    cin>>t;
    while(t--)
    {
        ans=INT_MAX;
        total=0;
        cin>>X;
        cin>>B;
        for(i=0;i<B;i++)
        {
            cin>>x>>y;
            pos.push_back(make_pair(x,make_pair(y,-1)));
            total+=y;
        }
        cin>>C;
        for(i=0;i<C;i++)
        {
            cin>>p>>q>>r;
            pos.push_back(make_pair(p,make_pair(q,r)));
        }
        if(C==0)
        {
            cout<<total+1<<endl;
        }
        else
        {
            sort(pos.begin(),pos.end());
            low=1;
            high=total+1;
            while(low<=high)
            {
                mid=low+(high-low)/2;
                if(possible(mid))
                {
                    ans=min(ans,mid);
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            cout<<ans<<endl;
        }
        pos.clear();
    }
    return 0;
}
