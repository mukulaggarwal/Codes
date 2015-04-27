#include<bits/stdc++.h>
using namespace std;

int fal=0;
int meet=0;
bool visited[101];
typedef pair<int,int> pairs;

class Graph
{
public:
    int V;
    list<pairs> *adj;
    Graph(int v);
    void addedge(int src,int dest,int type);
    void dfs(int src,int ans);
    void del();
};

Graph::Graph(int v)
{
    this->V=v;
    adj=new list<pairs>[v+1];
}

void Graph::addedge(int src,int dest,int type)
{
    adj[src].push_back(make_pair(dest,type));
}

void Graph::dfs(int src,int ans)
{
    visited[src]=true;
    list<pairs>::iterator it;
    for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(visited[it->first]!=true)
        {
            if(it->second==-1)
                fal++;
            dfs(it->first,ans);
        }
        if(it->first==ans)
        {
            if(it->second==-1)
                fal++;
            meet=1;
        }
    }
}

void Graph::del()
{
    delete[] adj;
}

int main()
{
    int n,i,val;
    char str[10];
    while(1)
    {
        scanf("%d",&n);
        Graph g(n);
        if(n==0)
            return 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d %s",&val,str);
            if(str[0]=='f')
                g.addedge(i,val,-1);
            else
                g.addedge(i,val,1);
        }
        //cout<<"insertion is done\n";
        int flag=0;
        for(i=1;i<=n;i++)
        {
            memset(visited,false,sizeof(visited));
            fal=0;
            meet=0;
            //cout<<i<<endl;
            g.dfs(i,i);
            if(fal%2&&meet)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("PARADOX\n");
        else
            printf("NOT PARADOX\n");
        g.del();
    }
}
