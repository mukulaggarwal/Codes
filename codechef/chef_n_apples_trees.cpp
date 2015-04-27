#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t,n,i,counter=0;
    scanf("%d",&t);
    while(t--)
    {
        counter=0;
        int value;
        scanf("%d",&n);
        int visited[100001]={0};
        for(i=0;i<n;i++)
        {
            scanf("%d",&value);
            if(visited[value]==0)
            {
                counter++;
                visited[value]=1;
            }
        }
        printf("%d\n",counter);
        for(i=0;i<100001;i++)
            visited[i]=0;
    }
    return 0;
}
