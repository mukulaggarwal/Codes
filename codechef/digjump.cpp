#include<bits/stdc++.h>
using namespace std;
bool vis[100011];

int main()
{
    vector<int> v[10];
    int val,i,j;
    char str[100001];
    scanf("%s",str);
    int n=strlen(str);
    for(i=0;i<n;i++)
    {
        val=str[i]-'0';
        v[val].push_back(i);
    }

    int dist[n+1];
    memset(dist,0,sizeof(dist));
    dist[0]=0;
    vis[0]=true;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty())
    {
        int id=Q.front();
        if(id==n-1)
            break;
        Q.pop();
        val=str[id]-'0';
        int sz=v[val].size();
        for(j=0;j<sz;j++)
        {
            if(!vis[v[val][j]])
            {
                vis[v[val][j]]=true;
                Q.push(v[val][j]);
                dist[v[val][j]]=dist[id]+1;
            }
        }
        v[val].clear();

        if(id-1>=0&&!vis[id-1])
        {
            vis[id-1]=true;
            dist[id-1]=dist[id]+1;
            Q.push(id-1);
        }
        if(id+1<n&&!vis[id+1])
        {
            vis[id+1]=true;
            dist[id+1]=dist[id]+1;
            Q.push(id+1);
        }
    }
    printf("%d\n",dist[n-1]);
    return 0;
}
