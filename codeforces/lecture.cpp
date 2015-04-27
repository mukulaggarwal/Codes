#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,string> mm;
    int i,n,m;
    char a[21],b[21];
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%s",a);
        scanf("%s",b);
        if(strlen(a)>strlen(b))
            mm[a]=b;
        else
            mm[a]=a;
    }
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        cout<<mm[a]<<" ";
    }
    return 0;
}
