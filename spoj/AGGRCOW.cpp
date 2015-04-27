#include<bits/stdc++.h>
using namespace std;

vector<long long> stall;
int main()
{
    long long t,n,c,i,prev,low,high,x;
    scanf("%lld",&t);
    while(t--)
    {
        stall.clear();
        scanf("%lld%lld",&n,&c);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            stall.push_back(x);
        }
        sort(stall.begin(),stall.end());
        low=0;
        high=stall[n-1];
        while(low<high)
        {
           // cout<<high<<" "<<low<<endl;
            long long cows=1;
            x=(low+high)/2;
            prev=stall[0];
            for(i=1;i<n;i++)
            {
                if(prev+x<=stall[i])
                {
                    //cout<<stall[i]<<endl;
                    prev=stall[i];
                    cows++;
                }
            }
            if(cows>=c)
                low=x+1;
            else
                high=x;
        }
        if(low>0)
        printf("%lld\n",low-1);
        else
            printf("0\n");
    }
    return 0;
}
