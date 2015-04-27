#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll b[10001],i;
    int val;
    for(i=1;i<=10000;i++)
    {
        b[i]=(i/2*(i/2-1))/2;
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&val);
        printf("%d\n",b[val]);
    }
    return 0;
}
