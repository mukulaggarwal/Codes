#include<cstdio>
#include<iostream>
using namespace std;


int binarysearch(int a[],int l,int r,int ans)
{
    int mid;
    while(l<=r)
    {
        if(l==r)
            return l;
        mid=l+(r-l)/2;
        if(a[mid]<ans)
            l=mid+1;
        else if(a[mid]>ans)
            r=mid-1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int n,i;
    cin>>n;
    int a[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans;
    cin>>ans;
    int flag=0;
    i=1;
    while(i<=n)
    {
        cout<<i<<endl;
        if(a[i]==ans)
        {
            flag=1;
            cout<<i<<endl;
            break;
        }
        if(a[i]>ans)
        {
            int prev=i;
            prev=prev>>1;
            cout<<binarysearch(a,prev,i,ans)<<endl;
            flag=1;
            break;
        }
        i=i<<1;
    }
    if(flag==0)
        cout<<"not found\n";
}
