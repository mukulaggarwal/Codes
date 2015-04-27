#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<iterator>
#include<cmath>
using namespace std;

typedef pair<long long int,long long int> pairs;

int main()
{
    long long int q,i,answer=0,x1,y1,x,y,n1,n,index=0;
    vector<pairs> vec;
    set<pairs> ss;
    set<pairs>::iterator it;
    pairs p;
    scanf("%lld",&q);
    char type;
    while(q--)
    {
         getchar();
        scanf("%c",&type);
        //cout<<type<<endl;
        if(type=='+')
        {
            scanf("%lld%lld",&x1,&y1);
            x=x1^answer;
            y=y1^answer;
             p.first=x;
            p.second=y;
            vec.push_back(p);
            ss.insert(p);
        }

        else if(type=='-')
        {
            scanf("%lld",&n1);
            n=n1^answer;
            x=vec[n].first;
            y=vec[n].second;
            p.first=x;
            p.second=y;
            vec.erase(vec.begin()+n-1);
            ss.erase(p);
        }

        else if(type=='?')
        {
            scanf("%lld%lld",&x1,&y1);
            x=x1^answer;
            y=y1^answer;
            long long int temp;
            for(it=ss.begin();it!=ss.end();it++)
            {
                p=*it;
                x1=p.first;
                y1=p.second;
                //cout<<"ffde "<<x1<<" "<<y1<<endl;
                 temp=abs(x1-x)+abs(y1-y);
                 if(temp>answer)
                    answer=temp;
            }
            printf("%lld\n",answer);
        }
    }
    return 0;
}
