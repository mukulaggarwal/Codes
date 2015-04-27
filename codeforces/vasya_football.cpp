#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct PLAYERS
{
    int time;
    int foul;
};
typedef struct PLAYERS play;
int main()
{
    int i,n,m,time;
    char a[23],b[23];
    char team,foul;
    scanf("%s",&a);
    scanf("%s",&b);
    scanf("%d",&n);
    play player[2][105];
    for(i=0;i<=103;i++)
    {
        player[0][i].foul=0;
        player[1][i].foul=0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&time);
        getchar();
        scanf("%c",&team);
        //cout<<"team is "<<team<<endl;
        scanf("%d",&m);
        getchar();
        scanf("%c",&foul);
        if(team=='h')
        {
            if(foul=='y')
            {
                player[0][m].foul++;
                player[0][m].time=time;
            }
            else
            {
                player[0][m].foul+=2;
                player[0][m].time=time;
            }
            if(player[0][m].foul>=2&&player[0][m].foul<=3)
            {
                printf("%s %d %d\n",a,m,player[0][m].time);
            }
        }
        else
        {
             if(foul=='y')
            {
                player[1][m].foul++;
                player[1][m].time=time;
            }
            else
            {
                player[1][m].foul+=2;
                player[1][m].time=time;
            }
            if(player[1][m].foul>=2&&player[1][m].foul<=3)
            {
                printf("%s %d %d\n",b,m,player[1][m].time);
            }
        }
    }
return 0;
}
