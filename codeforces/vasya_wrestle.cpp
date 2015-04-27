#include<cstdio>
#include<iostream>
using namespace std;
long long int f1[200001],f2[200001];
int main()
{
    long long int n,w,flag=1,w1=0,w2=0;
    long long int i=0,j=0,t1,t2;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld",&w);
        if(w>0)
        {
            w1+=w;
            f1[i]=w;
            flag=1;
            i++;
        }
        else
        {
            w=0-w;
            w2+=w;
            f2[j]=w;
            flag=2;
            j++;
        }
    }
    //cout<<w1<<" "<<w2<<" "<<f1<<" "<<f2<<" "<<flag<<endl;
    if(w1>w2)
    {
        printf("first\n");
    }
    else if(w2>w1)
    {
        printf("second\n");
    }
    else
    {
        long long int p,q,sflag=0;
        for(p=0,q=0;p<=i&&q<=j;p++,q++)
        {
            if(f1[p]>f2[q])
            {
                printf("first\n");
                sflag=1;
                break;
            }
            else if(f1[p]<f2[q])
            {
                printf("second\n");
                sflag=1;
                break;
            }
        }
        if(sflag==0)
        {
            if(flag==1)
                printf("first\n");
            else
                printf("second\n");
        }
    }
    return 0;
}
