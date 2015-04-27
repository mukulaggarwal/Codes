#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int n,i,m,k=1,j;
    cin>>n>>m;
    int a[n];
    for(i=0;i<n;i++)
        a[i]=i+1;
    sort(a,a+n);
    do
    {
        if(k==m)
        {
            for(j=0;j<n;j++)
                cout<<a[j]<<" ";
            break;
        }
        k++;
    }while(next_permutation(a,a+n));
    return 0;
}
