#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

vector<int> V[10010];
int vis[10010],dist[10010],k;
void dfs(int v,int n)
  {

            vis[v]=1;
            dist[v]=n;
            for(int u=0;u<V[v].size();u++)
             if(!vis[V[v][u]])
               dfs(V[v][u],n+1);

 }

int main()
  {
          int n,t1,t2;
          while(scanf("%d",&n)!=EOF)
            {
                 for(int i=0;i<n;i++)
                  V[i].clear(),vis[i]=0;

                 for(int i=0;i<n-1;i++)
                  {
                         scanf("%d%d",&t1,&t2);
                         V[t1-1].push_back(t2-1);
                         V[t2-1].push_back(t1-1);
                  }
                 dist[0]=0;
                 dfs(0,0);
                 /* for(int i=0;i<n;i++)
                  cout<<dist[i]<<" ";
                  cout<<endl;*/


                 int node=0;
                 for(int i=0;i<n;i++)
                  if(dist[i]>dist[node])
                    node=i;

                 memset(vis,0,sizeof(vis));
                // cout<<"node"<<node<<endl;

                 dfs(node,0);

                 /*for(int i=0;i<n;i++)
                  cout<<dist[i]<<" ";
                  cout<<endl;*/

                 sort(dist,dist+n);
                 cout<<dist[n-1]<<endl;


            }
 }
