#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    list<int> *adj;
    int V;
    Graph(int v);
    void addedge(int src,int dest);
    void bfs(int src);
};

Graph::Graph(int v)
{
    this->V=v;
    adj=new list<int>[V];
}

void Graph::addedge(int src,int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void Graph::bfs(int src)
{
    bool *visited=new bool[V];
    int i,current;
    for(i=0;i<V;i++)
        visited[i]=false;
    list<int> que;
    que.push_back(src);
    visited[src]=true;
    list<int>::iterator it;
    while(!que.empty())
    {
        current=que.front();
        cout<<current<<" ";
        que.pop_front();
        for(it=adj[current].begin();it!=adj[current].end();it++)
        {
            if(visited[*it]==false)
            {
                visited[*it]=true;
                que.push_back(*it);
            }
        }
    }
}

int main()
{
    int v,e;
    cout<<"enter the vertex and edges\n";
    cin>>v>>e;
    int i,src,dest;
    Graph g(v);
    for(i=0;i<e;i++)
    {
        cin>>src>>dest;
        g.addedge(src,dest);
    }
    g.bfs(0);
    return 0;
}
