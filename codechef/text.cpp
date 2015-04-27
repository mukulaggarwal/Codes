#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairs;
set<pairs> ss;
set<pairs>::iterator it;
pairs data;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,t,i,prev;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>data.first>>data.second;
            ss.insert(data);
        }
        int bomb=0;
        it=ss.begin();
        prev=it->second;
        while(it!=ss.end())
        {
            while(prev>=it->first)
            {
                prev=min(prev,it->second);
                it++;
                if(it==ss.end())
                    break;
            }

            bomb++;
            if(it==ss.end())
                break;
            prev=it->second;
            it++;
        }
        cout<<bomb<<endl;
    }
    return 0;
}
