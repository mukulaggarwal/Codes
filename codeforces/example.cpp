#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

char x[10000001];
int main()
{
    long long int a,b,first,second,len,i,j;
    scanf("%s",x);
    scanf("%lld%lld",&a,&b);
    len=strlen(x)-1;
    int flag=1;
    first=0;
    second=0;
    int sflag=0;
    if(a>b)
    {
        for(i=0;i<len;i++)
        {
            first=first*10+(x[i]-'0');
            //cout<<first<<endl;
            flag=1;
            if(first%a==0)
            {
                //cout<<"inside\n";
                for(j=i+1;j<=len;j++)
                {
                    if(x[j]=='0'&&flag==1)
                        first=first*10;
                    else
                    {
                        flag=0;
                        second=second*10+(x[j]-'0');
                    }
                }
               // cout<<"second "<<second<<endl;
                if(second%b==0&&second!=0)
                {
                    sflag=1;
                    printf("YES\n");
                    printf("%lld\n%lld\n",first,second);
                    break;
                }
            }
        }
        if(sflag==0)
            printf("NO\n");
    }

    else
    {
        for(i=len;i>0;i--)
        {
            second=second+pow(10,len-i)*(x[i]-'0');
            //cout<<second<<endl;
            if(second%b==0&&second!=0)
            {
               // cout<<"inside\n";
                for(j=0;j<i;j++)
                {
                    first=first*10+(x[j]-'0');
                }
                //cout<<first<<endl;
                if(first%a==0)
                {
                    sflag=1;
                    printf("YES\n");
                    printf("%lld\n%lld\n",first,second);
                    break;
                }
            }
        }

        if(sflag==0)
            printf("NO\n");
    }
    return 0;
}
