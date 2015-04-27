#include<cstdio>
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,i,count,value;
    cin>>t;
    while(t--)
    {
        int sum=0;
        count=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>value;
            if(value!=0)
                count++;
            sum=sum+value;
        }
        if(sum<100)
        {
            cout<<"NO\n";
        }
        else if(sum==100)
            cout<<"YES\n";
        else if(sum>100)
        {
            int diff=sum-100;
            float ans=(float)diff/(float)count;
            //cout<<ans<<endl;
            if(ans<1.0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
