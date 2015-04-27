#include<cstdio>
#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    set<int> ss;
    set<int>::iterator it;
    ss.clear();
    for(i=0;i<n;i++)
    {
        ss.insert(a[i]);
        it=ss.find(a[i]);
        it++;
        if(it!=ss.end())
        {
            ss.erase(it);
        }
    }
    cout<<"size  is "<<ss.size()<<endl;
    for(it=ss.begin();it!=ss.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}

