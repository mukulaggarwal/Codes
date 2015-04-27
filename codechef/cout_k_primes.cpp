#include<bits/stdc++.h>
using namespace std;
int main()
{
    int prime[6][100001]={0};
    int marked[100001]={0};
    int isprime[100001]={0};
    for(i=2;i<=100000;i++)
    {
        if(isprime[i]==0)
        {
            marked[i]++;
            for(j=2*i;j*j<=i;j=j+i)
            {
                isprime[j]=1;
                marked[j]++;
            }
        }
    }

    for(i=2;i<=100000;i++)
    {
        for(j=1;j<=5;j++)
        {
            prime[j][i]=prime[j-1][i];
        }
        int number=marked[i];
        if(number>=1&&number<=5)
        {
            prime[number][i]++;
        }
    }

}
