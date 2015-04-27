#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n,s1=0,i,s2=0,s3=0,val;
    scanf("%d",&n);
    vector<int> vec1,vec2,vec3;
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        if(val==1)
        {
            s1++;
            vec1.push_back(i+1);
        }
        else if(val==2)
        {
            s2++;
            vec2.push_back(i+1);
        }
        else if(val==3)
        {
            s3++;
            vec3.push_back(i+1);
        }
    }

    int teams=min(min(s1,s2),s3);
    printf("%d\n",teams);
    for(i=0;i<teams;i++)
    {
        printf("%d %d %d\n",vec1[i],vec2[i],vec3[i]);
    }
    return 0;
}
