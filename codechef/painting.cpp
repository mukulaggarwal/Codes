#include<cstdio>
#include<iostream>
#include<set>
#include<iterator>
#include<algorithm>
#include<map>
using namespace std;

typedef pair<unsigned long long int,unsigned long long int> pairs;
#define ull unsigned long long int
int main()
{
    unsigned long long int n,m,a,b,count,value,t,c;
    int h;
    pairs p;
    set<pairs> ss;
    set<pairs>::iterator it;
    scanf("%lld%lld%d",&n,&m,&h);
    while(h--)
    {
        scanf("%lld%lld",&a,&b);
        p.first=b;
        p.second=a;
        ss.insert(p);
    }


    /*multimap<int,ull> ss;
	multimap<int,ull> ::iterator it;
	scanf("%lld%lld%d",&n,&m,&h);
	for (int k = 0; k < h; k++) {
		scanf("%lld%lld",&t,&c);
		ss.insert(pair<ull,ull>(c,t));
	}*/

    count=n*m;
    value=0;
    it=ss.begin();
    while(it!=ss.end())
    {
        p=*it;
        if(count>=p.second)
        {
            value=value+(p.second*p.first);
            count=count-p.second;
        }
        else
        {
            value=value+(count*p.first);
            count=0;
        }
        if(count==0)
            break;
        it++;
    }
    if(count>0)
       printf("Impossible\n");
    else
        printf("%lld\n",value);
    return 0;
}
