#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct Pairs
{
    long long int range[4];
    long long int cpair[4][4];
};

struct Pairs chef[1000001];

 int main()
{
    char str[1000001];
    scanf("%s",str);
    long long int n=strlen(str);
    long long int i,j,k,type;
    long long int f,s;
    if(str[0]=='c')
        type=0;
    else if(str[0]=='h')
        type=1;
    else if(str[0]=='e')
        type=2;
    else
        type=3;
    chef[0].range[type]=chef[0].range[type]+1;
    for(i=1;i<n;i++)
    {
        if(str[i]=='c')
        type=0;
    else if(str[i]=='h')
        type=1;
    else if(str[i]=='e')
        type=2;
    else
        type=3;

        chef[i].range[type]=chef[i].range[type]+1;



        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                if(j!=k)
                chef[i].cpair[j][k]=chef[i-1].cpair[j][k];
            }
        }

        for(j=0;j<4;j++)
        {
            chef[i].range[j]=chef[i].range[j]+chef[i-1].range[j];
            if(j!=type)
                chef[i].cpair[j][type]=chef[i].cpair[j][type]+chef[i-1].range[j];
        }
    }

    long long int t,l,r;
    scanf("%lld",&t);
    char a,b;
    while(t--)
    {
        getchar();
        scanf("%c",&a);
        getchar();
        scanf("%c",&b);
        scanf("%lld%lld",&l,&r);
        l--;
        r--;
       // cout<<a<<" "<<b<<" "<<l<<" "<<r<<endl;
        if(a=='c')
            f=0;
        else if(a=='h')
            f=1;
        else if(a=='e')
            f=2;
        else
            f=3;

          if(b=='c')
            s=0;
        else if(b=='h')
            s=1;
        else if(b=='e')
            s=2;
        else
            s=3;
            long long int ans1=0,ans2=0,ans3=0;
            ans1=chef[r].cpair[f][s];
            if(l>0)
            {
             ans2=chef[l-1].cpair[f][s];
             ans3=chef[l-1].range[f]*(chef[r].range[s]-chef[l-1].range[s]);
            }
            printf("%lld\n",ans1-ans2-ans3);
    }
}
