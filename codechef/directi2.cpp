#include<bits/stdc++.h>
using namespace std;

int calc(char *str)
{
    int a[26]={0};
    memset(a,0,sizeof(a));
    int count=0;
    int n=strlen(str);
    for(int i=0;i<n;i++)
    {
        a[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(a[i])
            count++;
    }
    return count;
}
int main()
{
    int t,n,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        int result,ans=INT_MAX;
        scanf("%d",&n);
        char str1[20],str2[20];
        scanf("%s",str1);
        scanf("%s",str2);
        for(i=0;i<n;i++)
        {
            for(k=0;k<n;k++)
            {
                for(j=i;j<i+k;j++)
                {
                    char temp=str1[j];
                    str1[j]=str2[j];
                    str2[j]=temp;
                }
                int ans1=calc(str1);
                int ans2=calc(str2);
                result=max(ans1,ans2);

                 for(j=i;j<i+k;j++)
                {
                    char temp=str1[j];
                    str1[j]=str2[j];
                    str2[j]=temp;
                }

            }
            ans=min(ans,result);
        }
        printf("%d\n",ans);
    }
}
