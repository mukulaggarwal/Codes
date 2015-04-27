#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<long long> > vvi;
 typedef vector<long long> vi;

 vvi graph;
#define MOD 1000000007

int main()
{
    long long i,t,a,n,m,q,x,y,sz;
    char type[20];
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        for(i=0;i<=n;i++)
            graph.push_back(vi());
        for(i=0;i<=n;i++)
        {
            graph[i].push_back(0);
        }
        for(i=1;i<=n;i++)
        {
            cin>>a;
            graph[a].push_back(i);
            graph[i].push_back(a);
        }

        while(m--)
        {
            cin>>type;
            cin>>x>>y;
            if(type=="ADD")
            {
                graph[x][0]+=y%MOD;
            }
            else
            {
                i=x;
                while(graph[i][1]!=0)
                {
                    graph[i][0]+=y%MOD;
                    i=graph[i][1];
                }
                graph[i][0]+=y%MOD;

            }
        }

        while(q--)
        {
            cin>>type;
            cin>>x;
            if(type=="VAL")
            {
                cout<<graph[x][0]<<endl;
            }
            else
            {
                long long sum=0;
                queue<long long> Q;
                Q.push(x);
                while(!Q.empty())
                {
                    long long curr=Q.front();
                    Q.pop();
                    sum+=graph[curr][0]%MOD;
                    for(i=2;i<graph[curr].size();i++)
                    {
                        Q.push(graph[curr][i]);
                    }
                }
                cout<<sum<<endl;
            }
        }
        graph.clear();
    }
}
