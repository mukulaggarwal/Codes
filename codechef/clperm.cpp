#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,k,i,sum;
    cin>>t;
    while(t--)
    {
        ll val,prev=1,curr=0,i,flag=0;
        cin>>n>>k;
        sum=n*(n+1)/2;
        vector<ll> key;
        for(i=0;i<k;i++)
        {
            cin>>val;
            key.push_back(val);
        }
        sort(key.begin(),key.end());
        for(i=0;i<key.size();i++)
        {
            val=key[i];
             curr+=(val-prev)*(prev+val-1)/2;
             if(curr<val)
             {
                 flag=1;
                 if(curr%2!=0)
                    cout<<"Mom\n";
                 else
                    cout<<"Chef\n";
                break;
             }
            prev=val+1;
        }
        if(flag==0)
        {
        curr+=(n+1-prev)*(prev+n)/2;
        if(curr%2!=0)
            cout<<"Mom\n";
        else
            cout<<"Chef\n";
        }
    }
    return 0;
}
