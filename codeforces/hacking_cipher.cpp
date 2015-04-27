#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int i,a,b,first,second,len=0,n;
    scanf("%lld",&n);
    cout<<n;
    scanf("%lld%lld",&a,&b);
    long long int temp=n;
    while(temp)
    {
        temp=temp/10;
        len++;
    }
    cout<<len<<endl;
    first=n;
    //cout<<first<<endl;
    second=0;
    int flag=0;
    int sflag=0;

    second=first%10;
    first=first/10;
    for(i=len-1;i>0;i--)
    {
        cout<<"out "<<first<<" "<<second<<endl;
        if(first%10!=0)
        {
            if(flag>=1)
            {
                second=second+pow(10,len-i)*(first%10);
                first=first/10;
                flag=0;
                cout<<first<<" "<<second<<endl;
                if(first%a==0&&second%b==0&&a<=first&&b<=second)
                {
                    sflag=1;
                    printf("YES\n");
                    printf("%lld\n%lld\n",first,second);
                    break;
                }
            }
            else
            {
                second=10*(first%10)+second;
                first=first/10;
                flag=0;
                cout<<first<<" "<<second<<endl;
                if(first%a==0&&second%b==0&&a<=first&&b<=second)
                {
                    sflag=1;
                    printf("YES\n");
                    printf("%lld\n%lld\n",first,second);
                    break;
                }
            }
        }
        else
        {
            flag++;
            first=first/10;
        }
    }
    if(sflag==0)
        printf("NO\n");
    return 0;
}
