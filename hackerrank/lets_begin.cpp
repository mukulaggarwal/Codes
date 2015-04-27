#include<cstdio>
#include<iostream>
#include<cstdlib>
int prime(int n,int count)
{
    if(n==0)
        return count;
    if(n==1)
        return -1;
    if(prime(n-7,count)!=-1)
        return count+1;
    else if(prime(n-5,count)!=-1)
        return count+1;
    else if(prime(n-3,count)!=-1)
        return count+1;
    else if(prime(n-2,count)!=-1)
        return count;
}

int main()
{
    int t,n,ans;
    scanf("%d",&t);
    while(t--)
    {
        int count=0;
        scanf("%d",&n);
        printf("%d\n",prime(n,0));
    }
    return 0;
}
