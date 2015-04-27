#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarysearchrotated(int a[],int left,int right,int data)
{
    int mid=left+(right-left)/2;
    if(left>right)
        return -1;
    if(left<right)
    {
        if(data==a[mid])
            return mid;
        if(a[left]<=a[mid])
        {
            if(data<a[mid]&&data>=a[left])
                return binarysearchrotated(a,left,mid-1,data);
            else
                return binarysearchrotated(a,mid+1,right,data);
        }
        else
        {
            if(data>a[mid]&&data<=a[right])
               return  binarysearchrotated(a,mid+1,right,data);
            else
                return binarysearchrotated(a,left,mid-1,data);
        }
    }
}

int firstoccur(int a[],int start,int last,int data)
{
    int mid=start+(last-start)/2;
    if(last>=start)
    {
        if((a[mid]==data&&mid==start)||(a[mid]==data)&&a[mid-1]<data)
            return mid;
        else if(a[mid]>=data)
            return firstoccur(a,start,mid-1,data);
        else
            return firstoccur(a,mid+1,last,data);
    }
    return -1;
}

int lastoccur(int a[],int start,int last,int data)
{
    int mid=start+(last-start)/2;
    if(start<=last)
    {
        if((a[mid]==data&&mid==last)||(a[mid]==data&&a[mid+1]>data))
            return mid;
        else if(data>=a[mid])
            return lastoccur(a,mid+1,last,data);
        else
            return lastoccur(a,start,mid-1,data);
    }
    return -1;
}
int main()
{
    int n,i,j,val;
    int a[100];
    /*cout<<"circular sorted array\n";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>val;
    cout<<binarysearchrotated(a,0,n-1,val)<<endl;*/

    cout<<"number of occurrences\n";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>val;
    cout<<lastoccur(a,0,n-1,val)-firstoccur(a,0,n-1,val)+1<<endl;

}
