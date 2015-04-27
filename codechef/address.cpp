#include<bits/stdc++.h>
using namespace std;

multimap<string, vector<string> > customer;
vector< vector<string> > inp;
vector<string> word,current,tmp;

multimap<string, vector<string> >::iterator itc;

std::string::size_type matching_characters(std::string s1, std::string s2) {
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  std::string intersection;
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                        back_inserter(intersection));
  return intersection.size();
}

int main() {
 // std::cout << matching_characters("an", "assingn") << '\n';     // 6
  //std::cout << matching_characters("sisdirturn", "disturb") << '\n'; // 6

  long long n,i,j,count,res,ID;
  cin>>n;
  for(i=0;i<n;i++)
  {
     for (string word; cin >> word; i++)
     {
         std::istringstream ss(word);
        std::string token;

        while(std::getline(ss, token, ' ')) {
       if(word!="!"&&word!="@"&&word!="#"&&word!="$"&&word!="^"&&word!="&"&&word!="*"&&word!="("&&word!=")"&&word!=",")
            tmp.push_back(word);
        }


     }
    inp.push_back(tmp);
    tmp.clear();
  }
  for(i=0;i<n;i++)
  {
      for (string word; cin >> word; i++)
     {
         std::istringstream ss(word);
        std::string token;

        while(std::getline(ss, token, ' ')) {
       if(word!="!"&&word!="@"&&word!="#"&&word!="$"&&word!="^"&&word!="&"&&word!="*"&&word!="("&&word!=")"&&word!=",")
            tmp.push_back(word);
        }


     }
    customer.insert(make_pair(tmp[1],tmp));
    tmp.clear();
  }

  for(i=0;i<n;i++)
  {
      string ans;
      current.clear();
      current=inp[i];
      itc=customer.find(current[1]);
      //cout<<"current is "<<current[0]<<" "<<current[1]<<endl;
      count=0;
      res=0;
      for(itc;itc!=customer.end()&&itc->first==current[1];itc++)
      {
           count=0;
         tmp.clear();
         tmp=itc->second;
         //cout<<"tmp is "<<tmp[0]<<" "<<tmp[1]<<endl;
         for(j=1;j<tmp.size();j++)
         {
             if(current[j]==tmp[j])
                count++;
             //count+=matching_characters(current[j],tmp[j]))/strlen(current[j]);
         }
         if(count>res)
         {
             res=count;
             ans=tmp[0];
             cout<<"got\n";
         }
      }
      cout<<current[0]<<","<<ans<<endl;
  }
return 0;
}
