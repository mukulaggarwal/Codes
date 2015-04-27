#include<bits/stdc++.h>
using namespace std;
long long dist[11111];
bool visited[11111];
#define pii pair<long long,long long>
typedef long long ll;
vector<pii> G[10005];
struct cmp
{
    bool operator()(const pii &a,const pii &b)
    {
        return a.second>b.second;
    }
};

priority_queue< pii ,vector<pii> ,cmp > Q;

void dijkstras(int src)
{
    dist[src]=0;
    Q.push(pii(src,0));
    while(!Q.empty())
    {
        ll u=Q.top().first;
        Q.pop();
        if(visited[u])
        continue;
        ll sz=G[u].size();
        for(ll i=0;i<sz;i++)
        {
            ll v=G[u][i].first;
            ll wt=G[u][i].second;
            if(dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
                Q.push(pii(v,dist[v]));
            }
        }
        visited[u]=true;
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    ll s,n,r,src,dest,wt,i,p,j;
    char str[20],str1[20],str2[20];
    scanf("%lld",&s);
    while(s--)
    {
        map<string,long long> mp;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            //scanf("%s",str);
            //cin>>str;
            scanf("%s",str);

            mp[str]=i;
           // cout<<mp[str]<<endl;
            src=i;
            scanf("%lld",&p);
            for(j=0;j<p;j++)
            {
                scanf("%lld%lld",&dest,&wt);
                G[src].push_back(pii(dest,wt));
            }
        }
        scanf("%lld",&r);
        while(r--)
        {
            for(ll i=0;i<=n;i++)
                dist[i]=111111;
            memset(visited,false,sizeof(visited));

            scanf("%s %s",str1,str2);
            //cin>>str1>>str2;
            src=mp[str1];
            dest=mp[str2];
            //cout<<src<<" "<<dest<<endl;
            dijkstras(src);
            printf("%lld\n",dist[dest]);
        }
            for(ll i=0;i<10005;i++)
                G[i].clear();
        while(!Q.empty())
            Q.pop();
    }
    return 0;
}
