#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

typedef pair<int,int> ii;
typedef vector< ii > vii;
typedef vector< vii > vvii;

vector< vector< pair<int,int> > > Graph;

int *dist;

void dijkstras(int src)
{
    priority_queue<ii, vii, greater <ii> > Q;
    dist[0]=0;
    Q.push(ii(0,0));
    while(!Q.empty())
    {
        ii top=Q.top();
        Q.pop();
        int v=top.second;
        int d=top.first;
        if(d<=dist[v])
        {
            tr(Graph[v],it)
            {
                int v2=it->first;
                int cost=it->second;
                if(dist[v2]>dist[v]+cost)
                {
                    dist[v2]=dist[v]+cost;
                    Q.push(ii(dist[v2],v2));
                }
            }
        }
    }
}

int main()
{
    int v,e,s,d,w,i;
    cin>>v>>e;

    for(i=0;i<v;i++)
        Graph.push_back(vii());
    for(i=0;i<e;i++)
    {
        cin>>s>>d>>w;
        Graph[s].push_back(make_pair(d,w));
    }
    dist=(int*)malloc(v*sizeof(int));
    memset(dist,INT_MAX,sizeof(dist));
    dijkstras(0);
    cout<<dist[2];
}
