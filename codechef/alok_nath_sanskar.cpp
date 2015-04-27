#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long long int n,i,k,t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int val,sum=0;
        scanf("%lld%lld",&n,&k);
        vector<long long int> s;
        vector<long long int>:: iterator it1,it2;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&val);
            sum+=val;
            s.push_back(val);
        }
        sort(s.begin(),s.end());
        if(sum%k!=0)
        {
            printf("no\n");
        }
        else
        {
            int counter=0;
            val=sum/k;
            it1=s.begin();
            int l=1,h=n;
            it2=s.end();
            it2--;
            while(l<h)
            {
                if(*it2==val)
                {
                    h--;
                    it2--;
                    counter++;
                }
                else if(*it2+*it1==val)
                {
                    l++;
                    h--;
                    it1++;
                    it2--;
                    counter+=2;
                }
                else if(*it1==val)
                {
                    l++;
                    it1++;
                    counter++;
                }
                else
                {
                    counter=0;
                    break;
                }
            }
            if(counter==n)
            {
                printf("yes\n");
            }
            else
                printf("no\n");
        }
    }
    return 0;
}
