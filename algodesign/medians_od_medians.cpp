#include<cstdio>
#include<iostream>
using namespace std;
int a[100];
int partitions(int low,int high)
{
    int l=low,r=high,i=l-1,x=a[r];
    for(int j=l;j<=r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
            int temp=a[i+1];
            a[i+1]=a[r];
            a[r]=temp;
            return i+1;
}

int selection(int low,int high,int k)
{
    int piv;
    while(1)
    {
        piv=partitions(low,high);
        int len=piv-low+1;
        if(len==k)
            return a[piv];
        else if (len>k)
            high=piv-1;
        else
        {
            k=k-len;
            low=piv+1;
        }
        //cout<<k<<" "<<len<<endl;
    }
    return -1;
}
int main()
{
    int i,k,n;
    cout<<"enter \n";
    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter k \n";
    cin>>k;
    cout<<selection(1,n,k)<<endl;
    return 0;
}
