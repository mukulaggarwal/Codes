#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i;
    char str[1000];
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        scanf("%s",str);
        char first=str[0];
        char sec=str[1];
        n=strlen(str);
        if(first!=sec)
        {
            for(i=2;i<n;i++)
            {
                if(i%2==0&&first!=str[i])
                {
                    flag=1;
                    break;
                }
                else if(i%2&&sec!=str[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                printf("NO\n");
            }
            else
                printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
