#include<bits/stdc++.h>
using namespace std;

typedef pair<string,string> pairs;

vector< pair< pair< string,string>, pair<string,string> > > ID;
multimap<string,pairs> relation,primary;
map<string,string> card;
vector<pair<string,string> >known;
map<string,string> result;
map<string,long long> check;
vector<pair<string,string> >::iterator it;
multimap<string,pairs>::iterator itf;
vector< pair<string,string> >::iterator res;
map<string,string>::iterator ch;
map<string,long long> visited;
queue<string> que;
vector<string> values;
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    long long n,i,k,cardId;
    scanf("%lld",&n);
    scanf("%lld",&k);
    string c,p,s,h,card,prim,sec,household;
    for(i=0;i<n;i++)
    {
        cin>>str;
        std::istringstream ss(str);
        std::string token;

        while(std::getline(ss, token, ',')) {
        values.push_back(token);
        }
        c=values[0];
        p=values[1];
        s=values[2];
        h=values[3];
        //cout<<c<<" "<<p<<" "<<s<<" "<<h<<endl<<endl<<endl;
        values.clear();
        ID.push_back(make_pair(make_pair(c,p),make_pair(s,h)));
        relation.insert(make_pair(s,make_pair(p,c)));
        primary.insert(make_pair(p,make_pair(s,c)));
        if(h!="?")
        {
            known.push_back(make_pair(h,s));
        }
    }

    for(it=known.begin();it!=known.end();it++)
    {
        household=it->first;
        sec=it->second;
        //cout<<"household "<<household<<endl;
        if(check.find(household)==check.end())
        {
            que.push(sec);
            check.insert(make_pair(household,1));
            //cout<<"enter"<<endl;
        while(!que.empty())
        {
            sec=que.front();
            que.pop();
            itf=relation.find(sec);
            for(itf;itf!=relation.end()&&itf->first==sec;itf++)
            {
                //cout<<"card is "<<itf->second.second<<endl;
                if(visited.find(itf->second.second)==visited.end())
                {
                    visited.insert(make_pair(itf->second.second,1));
                    if(itf->second.first!=itf->first)
                    {
                        que.push(itf->second.first);
                        //cout<<"inserted in que\n";
                    }
                    result.insert(make_pair(itf->second.second,household));
                }

            }

            itf=primary.find(sec);
            for(itf;itf!=primary.end()&&itf->first==sec;itf++)
            {
                //cout<<"card is "<<itf->second.second<<endl;
                if(visited.find(itf->second.second)==visited.end())
                {
                    visited.insert(make_pair(itf->second.second,1));
                    if(itf->second.first!=itf->first)
                    {
                        que.push(itf->second.first);
                        //cout<<"inserted in que\n";
                    }
                    result.insert(make_pair(itf->second.second,household));
                }

            }
        }
    }
    }

    for(i=0;i<n;i++)
    {
        cout<<ID[i].second.second<<endl;
        if(ID[i].second.second=="?")
        {
            string ans=result.find(ID[i].first.first)->second;
            cout<<ID[i].first.first<<","<<ans<<endl;
        }
    }
}
