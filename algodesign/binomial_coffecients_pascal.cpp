#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    int n,k;
    int i;
    cin>>n>>k;
    int  row[n+1];
    row[0]=1;
    for(i=1;i<(n/2)+1;i++)
    {
        row[i]=row[i-1]*((double)(n-i+1)/i);
    }
    for(i=n/2+1;i<=n;i++)
        row[i]=row[n-i];
    cout<<row[k]<<endl;
    return 0;
}
