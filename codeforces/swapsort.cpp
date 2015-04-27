#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long int n,i,value,j;
    scanf("%lld",&n);
    vector<long long int> a,b;
    vector< pair<long long int,long long int> > ans;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&value);
        a.push_back(value);
        b.push_back(value);
    }

    sort(b.begin(),b.end());
    long long int swaps=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]==b[i])
                {
                    swaps++;
                    ans.push_back(make_pair(i,j));
                    swap(a[j],a[i]);
                    break;
                }
            }
        }
    }
    printf("%lld\n",swaps);
    for(i=0;i<swaps;i++)
    {
        printf("%lld %lld\n",ans[i].first,ans[i].second);
    }
    return 0;
}
