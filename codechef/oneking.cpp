#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pairs;
set<pairs> ss;
set<pairs>::iterator itb,ite;
pairs data;
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,t,i,prev,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>l>>r;
            data.first=l;
            data.second=r;
            ss.insert(data);
        }
        long long bomb=0;
        itb=ss.begin();
        ite=ss.begin();
        ite++;
        while(itb!=ss.end())
        {
            prev=itb->second;
            while(prev>=ite->first&&ite!=ss.end())
            {
                prev=min(prev,ite->second);
                ite++;
            }
            bomb++;
            if(ite==ss.end())
                break;
            itb=ite;
            ite++;
        }
        cout<<bomb<<endl;
        ss.clear();
    }
    return 0;
}
