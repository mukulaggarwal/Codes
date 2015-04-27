#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char x[1000001];

int main()
{
    int t1=0,t2=0,i,count=0,type=0,t3=0;
    scanf("%s",&x);

    for(i=0;i<strlen(x);i++)
    {
        if(x[i]=='(')
            t1++;
        else if(x[i]==')')
            t2++;
        else if(x[i]=='#')
        {
                t3++;
                t2++;
                if(t2>=t1)
                {
                    t1=-1;
                    printf("-1\n");
                    break;
                }

        }
    }
    if(t2>t1&&t1!=-1)
        printf("-1\n");

    else if(t1!=-1)
    {
        for(i=0;i<t3-1;i++)
        {
            printf("1\n");
        }
        printf("%d\n",t1-t2+1);
    }
    return 0;
}
