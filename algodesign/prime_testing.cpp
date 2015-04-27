#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i,flag=0;;
    if(n<=1)
        cout<<"no\n";
    else if(n==2)
        cout<<"yes\n";
    else if(n%2==0)
        cout<<"no\n";
    else
    {
        for(i=3;i*i<=n;i=i+2)
        {
            if(n%i==0)
            {
                flag=1;
                cout<<"no\n";
                break;
            }
        }
        if(!flag)
        cout<<"yes\n";
    }
}
