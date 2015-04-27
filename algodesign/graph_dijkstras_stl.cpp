#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

#define MAX 100
vector< pii > G[MAX];
bool visited[MAX];
int dist[MAX];
int v,e;
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
priority_queue< pii, vector< pii >, comp > Q;

void dijkstras(int src)
{
    int i;
    dist[src]=0;
    Q.push(pii(src,0));
    while(!Q.empty())
    {
        int u = Q.top().first;
        Q.pop();
        if(visited[u])
            continue;
        //cout<<u<<endl;
        int sz=G[u].size();
        for(i=0;i<sz;i++)
        {
            //cout<<"inside\n";
          int v=G[u][i].first;
          int w=G[u][i].second;
          cout<<v<<" "<<w<<" "<<visited[v]<<endl;
          if(!visited[v]&&dist[v]>dist[u]+w)
          {
              dist[v]=dist[u]+w;
              Q.push(pii(v,dist[v]));
             // cout<<"pushing"<<endl;
          }
        }
        visited[u]=true;
    }
}

int main()
{
    int i,src,dest,wt,ver;
    cin>>ver>>e;
    for(i=0;i<e;i++)
    {
        cin>>src>>dest>>wt;
        G[src].push_back(pii(dest,wt));
        G[dest].push_back(pii(src,wt));
    }
    memset(dist,1111,sizeof(dist));
    memset(visited,false,sizeof(visited));
    dijkstras(1);
    printf("dist\n");
    for(i=1;i<=ver;i++)
        cout<<i<<" "<<dist[i]<<endl;
}
