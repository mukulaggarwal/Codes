#include<bits/stdc++.h>
using namespace std;

bool *visited;
class Graph
{
public:
    int V;
    list<int> *adj;
    Graph(int v);
    void addedge(int src,int dest);
    void dfs(int src);
};

Graph::Graph(int v)
{
    this->V=v;
    adj=new list<int>[v];
}

void Graph::addedge(int src,int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void Graph::dfs(int src)
{
    cout<<src<<" ";
    visited[src]=true;
    list<int>::iterator it;
    for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(visited[*it]!=true)
            dfs(*it);
    }
}

int main()
{
    int i,v,e,src,dest,connected=0;
    cout<<"vertex and edge\n";
    cin>>v>>e;
    Graph g(v);
    visited=new bool[v];
    for(i=0;i<v;i++)
        visited[i]=false;
    for(i=0;i<e;i++)
    {
        cin>>src>>dest;
        g.addedge(src,dest);
    }
    for(i=0;i<v;i++)
    {
        if(visited[i]!=true)
        {
            connected++;
            g.dfs(i);
        }
    }
    cout<<"connected comp "<<connected<<endl;
    return 0;
}
