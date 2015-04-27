#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int b,g,n,i,j,pairs=0,val,nu;
    scanf("%d",&b);
    int boys[b+1];
    for(i=0;i<b;i++)
    {
        scanf("%d",&boys[i]);
    }

    scanf("%d",&g);
    int girls[g+1];
    for(i=0;i<g;i++)
    {
        scanf("%d",&girls[i]);
    }
    sort(girls,girls+g);
    sort(boys,boys+b);
    i=0;
    j=0;
    while(i<b&&j<g)
    {
        if(boys[i]==girls[j]||abs(boys[i]-girls[j])==1)
        {
            pairs++;
            i++;
            j++;
        }
        else if(boys[i]>girls[j])
        {
            j++;
        }

        else if(boys[i]<girls[j])
            i++;
    }
    printf("%d\n",pairs);
    return 0;
}
