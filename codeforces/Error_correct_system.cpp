#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef  pair<char, pair<char,int> > pairs;
int main()
{
    int n,i,j,x,y,count=0,flag=0;
    char s[200001],t[200001];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%s",t);
    vector<pairs> v;
    //cout<<v.size();
    for(i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            if(v.size()!=0)
            {
                for(j=0;j<v.size();j++)
                {
                    if(v[j].first==t[i]&&v[j].second.first==s[i])
                    {
                        flag=2;
                        x=v[j].second.second;
                        y=i;
                        break;
                    }
                    if(v[j].first==t[i]||v[j].second.first==s[i])
                    {
                        flag=1;
                        x=v[j].second.second;
                        y=i;
                    }
                }
            }
                pairs temp;
                temp.first=s[i];
                temp.second.first=t[i];
                temp.second.second=i;
                v.push_back(temp);

        }
        if(flag==2)
            break;
    }
    if(flag==0)
    {
        for(i=0;i<n;i++)
        {
            if(s[i]!=t[i])
                count++;
        }
        printf("%d\n",count);
        printf("-1 -1\n");
    }
    else
    {
        char tem;
        tem=s[x];
        s[x]=s[y];
        s[y]=tem;
        for(i=0;i<n;i++)
        {
            if(s[i]!=t[i])
                count++;
        }
        printf("%d\n",count);
        printf("%d %d\n",x+1,y+1);
    }
    return 0;
}
