#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    int n,n3,n5,n8,count=0,value,temp,i;
    char x[1001];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        int flag=0;
        n3=0;
        n5=0;
        n8=0;
        gets(x);
        //puts(x);
        for(i=strlen(x)-1;i>=0;i--)
            if(x[i]==' ')
                break;
        value=atoi(x+i+1);
        while(value)
        {
            temp=value%10;
            if(temp==3)
                n3++;
            else if(temp==5)
                n5++;
            else if(temp==8)
                n8++;
            else
            {
                flag=1;
                break;
            }
            value=value/10;
        }
        if(flag==0&&n8>=n5&&n5>=n3)
            count++;
    }
    printf("%d\n",count);
    return 0;
}
