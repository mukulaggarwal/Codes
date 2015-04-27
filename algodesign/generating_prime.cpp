#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    int prime[n+1];
    for(i=1;i<=n;i++)
        prime[i]=1;
    for(i=2;i*i<=n;i++)
    {
        if(prime[i])
        {
            for(j=i*i;j<=n;j=j+i)
            {
                prime[j]=0;
            }
        }
    }
    for(i=1;i<=n;i++)
        if(prime[i])
        cout<<i<<" ";
}
