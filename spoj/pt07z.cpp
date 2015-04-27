#include<bits/stdc++.h>
using namespace std;
long long length=0;
int flag=0;
int last;

bool visited[11111];
int dist[11111];
class Graph
{
public:
    int V;
    list<int> *adj;
    Graph(int v);
    void addedge(int src,int dest);
    void dfs(int src,int n);
};

Graph::Graph(int v)
{
    this->V=v;
    adj=new list<int>[v+1];
}

void Graph::addedge(int src,int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void Graph::dfs(int src,int n)
{

    visited[src]=true;
    list<int>::iterator it;
    dist[src]=n;
    for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(visited[*it]==false)
        {
            visited[*it]=true;
            dfs(*it,n+1);
        }
    }
}


int main()
{
    int n,i,src,dest;
    long long maxlen=0;
    scanf("%d",&n);
    Graph g(n+1);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&src,&dest);
        g.addedge(src,dest);
    }
    memset(dist,0,sizeof(dist));
    memset(visited,false,sizeof(visited));
    g.dfs(1,0);
    int node=0;
    for(i=1;i<=n;i++)
    {
        if(dist[i]>dist[node])
        {
            node=i;
        }
    }
    memset(visited,false,sizeof(visited));
    g.dfs(node,0);
    sort(dist,dist+n+1);
    printf("%d\n",dist[n]);
    return 0;
}
