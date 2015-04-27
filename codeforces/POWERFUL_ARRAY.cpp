#include<bits/stdc++.h>
using namespace std;

int block=1;
map<int,int> occur;
map<int,int>:: iterator it;
vector<int> a;
int answer=0;
int elements[1000001];
struct Query
{
    int l,r,i;
};
typedef struct Query query;

 bool cmp(query x, query y)
 {
     if(x.l/block!=y.l/block)
        return x.l/block<y.l/block;
     else
        x.r<y.r;
 }

 void Add(int n)
 {
   answer=answer-elements[a[n-1]]*elements[a[n-1]]*a[n-1];
   elements[a[n-1]]++;
   answer+=elements[a[n-1]]*elements[a[n-1]]*a[n-1];
 }

 void Remove(int n)
 {
   answer=answer-elements[a[n-1]]*elements[a[n-1]]*a[n-1];
   elements[a[n-1]]--;
   answer+=elements[a[n-1]]*elements[a[n-1]]*a[n-1];
 }

int main()
{
    int n,t,i,j,l,r,val,currentl,currentr;
    scanf("%d%d",&n,&t);
    //cin>>n>>t;
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        //cin>>val;
        a.push_back(val);
        //occur[val]=0;
    }
    query q[t+1];
    answer=0;
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        //cin>>q[i].l>>q[i].r;
        q[i].i=i;
    }
    int ans[t+1];
    block=ceil(sqrt(n+1));
    sort(q,q+t,cmp);
    currentl=1;
    currentr=1;
    for(j=0;j<t;j++)
    {
        l=q[j].l;
        r=q[j].r;
        i=q[j].i;
        while(currentl<l)
        {
            Remove(currentl);
            currentl++;
        }
        while(currentl>l)
        {
            Add(currentl-1);
            currentl--;
        }
        while(currentr<=r)
        {
            Add(currentr);
            currentr++;
        }
        while(currentr>r+1)
        {
            Remove(currentr-1);
            currentr--;
        }
        ans[i]=answer;
    }

    for(i=0;i<t;i++)
        printf("%d\n",ans[i]);
        //cout<<ans[i]<<endl;
    //occur.clear();
    return 0;
}
