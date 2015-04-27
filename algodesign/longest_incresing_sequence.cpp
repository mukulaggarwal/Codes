#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int a[n+1],t[n+1],prev[n+1],l,r,mid,length=1,pos;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    length=1;
    t[0]=0;
    prev[0]=-1;
    for(i=1;i<n;i++)
    {
        if(a[i]<a[t[0]])
        {
            t[0]=i;
        }
        else if(a[i]>a[t[length-1]])
        {
            prev[i]=t[length-1];
            t[length]=i;
            length++;
        }
        else
        {
            r=length-1;
            l=-1;
            while(r-l>1)
            {
                mid=l+(r-l)/2;
                if(a[t[mid]]>=a[i])
                    r=mid;
                else
                    l=mid;
            }
            pos=r;
            prev[i]=t[pos-1];
            t[pos]=i;
        }
    }

    int j;
    cout<<"length is "<<length<<endl;
    for(i=t[length-1],j=0;i>=0&&j<length;i=prev[i],j++)
    {
        cout<<a[i]<<" ";
    }
}
