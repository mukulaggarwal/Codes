#include<cstdio>
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int main()
{
    int n,i,j,k,l,nu,ans;
    scanf("%d",&n);
    int a[n+1];
    char val[10001];
    char fin[10001];
    scanf("%d",&ans);
    for(i=1;i<=n;i++)
    {
        a[n-i]=ans%10;
        ans=ans/10;
        //cout<<a[n-i]<<endl;
    }
    int start,zero_index[n+1],result=INT_MAX;
    //cout<<"1st\n";
    for(i=0;i<n;i++)
    {
        int m=10-a[i];
        k=0;
        for(j=0;j<n;j++)
        {
            if((a[j]+m)%10==0)
            {
                zero_index[k++]=j;
                //cout<<"zero "<<j<<endl;
            }
        }
        nu=0;
        for(j=0;j<k;j++)
        {
            int c;
            start=zero_index[j];
            //cout<<"in\n";
            for(l=(start)%n,c=0;c<n;l=(l+1)%n,c++)
            {
                nu=nu*10+(a[l]+m)%10;
                val[c]=(a[l]+m)%10+48;
                //cout<<val[c]<<endl;
            }
            //cout<<"nu is "<<nu<<endl;
            if(nu<result)
            {
                result=nu;
                strcpy(fin,val);
                //cout<<fin<<endl;
            }
        }
    }
    printf("%s\n",fin);
    return 0;
}
