#include<bits/stdc++.h>
using namespace std;
int dist[11111];
bool visited[11111];
#define pii pair<int,int>

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
        int u=Q.top().first;
        Q.pop();
        if(visited[u])
        continue;
        int sz=G[u].size();
        for(int i=0;i<sz;i++)
        {
            int v=G[u][i].first;
            int wt=G[u][i].second;
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
    ios_base::sync_with_stdio(0);
    int t,src,dest,wt,v,e;
    cin>>t;
    while(t--)
    {
        cin>>v>>e;
        for(int i=0;i<e;i++)
        {
            cin>>src>>dest>>wt;
            G[src].push_back(pii(dest,wt));
        }

        for(int i=0;i<=v;i++)
            dist[i]=111111;
        memset(visited,false,sizeof(visited));
        cin>>src>>dest;
        dijkstras(src);
        if(dist[dest]!=111111)
            cout<<dist[dest]<<endl;
        else
            cout<<"NO\n";
        for(int i=0;i<10005;i++)
            G[i].clear();
        while(!Q.empty())
            Q.pop();
    }
    return 0;
}
