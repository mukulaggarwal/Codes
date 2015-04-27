#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    int n,i,next,min2,min3,min5,i2=0,i3=0,i5=0;
    cin>>n;
    int ugly[n+1];
    ugly[0]=1;
    min2=2;
    min3=3;
    min5=5;
    for(i=1;i<n;i++)
    {
        next=min(min(min2,min3),min5);
        cout<<next<<endl;
        ugly[i]=next;
        if(next==min2)
        {
            i2=i2+1;
            min2=ugly[i2]*2;
        }
         if(next==min3)
        {
            i3=i3+1;
            min3=ugly[i3]*3;
        }
         if(next==min5)
        {
            i5=i5+1;
            min5=ugly[i5]*5;
        }
    }
    cout<<endl<<endl<<ugly[n-1]<<endl;
    return 0;
}
