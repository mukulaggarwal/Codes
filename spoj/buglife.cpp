#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int color[2111];

class Graph{
public:
    int V;
    list<int> *adj;
    Graph(int v);
    void addedge(int src,int dest);
    bool isbipartite(int src,int sex);
    void del();
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

bool Graph::isbipartite(int src,int sex)
{
    color[src]=sex;
    sex=1-sex;
    list<int>::iterator it;
    //cout<<"src is "<<src<<" sex is "<<sex<<endl;
    for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(color[*it]==1-sex)
            return false;
        else if(color[*it]==2)
        {
            color[*it]=sex;
            if(isbipartite(*it,sex)==false)
                return false;
        }
    }
    return true;
}

void Graph::del()
{
    delete[] adj;
}
int main()
{
    int t,v,i,src,dest,sc,k=0;
    scanf("%d",&t);
    while(t--)
    {
        k++;
        scanf("%d%d",&v,&sc);
        Graph g(v+1);
        for(i=1;i<=sc;i++)
        {
            scanf("%d%d",&src,&dest);
            g.addedge(src,dest);
        }
        int flag=0;
        for(i=0;i<=v;i++)
            color[i]= 2;
        for(i=1;i<=v;i++)
        {
            //cout<<color[i]<<endl;
            int sex=0;
            if(color[i]==2)
            {
                if(g.isbipartite(i,sex)==false)
                {
                    flag=1;
                    break;
                }
            }
        }
        printf("Scenario #%d:\n",k);
        if(flag)
        {
            printf("Suspicious bugs found!\n");
        }
        else
            printf("No suspicious bugs found!\n");

        g.del();
    }
    return 0;
}
