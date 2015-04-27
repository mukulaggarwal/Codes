#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
    int t,n,m,i;
    vector<string> st;

    scanf("%d",&t);
    while(t--)
    {
        string str;
        st.clear();
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            cin>>str;
            if(i==0)
            {
                st.push_back(str);
            }
            else
            {
                string temp=st[i-1];
                string temp2=temp;
                reverse(temp2.begin(),temp2.end());
                temp.append(temp2);
                temp.append(str);
                st.push_back(temp);
            }
        }
        str=st[i-1];
        vector<char> ans;
        for(i=0;i<m;i++)
        {
            scanf("%d",&n);
           ans.push_back(str[n]);
        }
        for(i=0;i<m;i++)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
    }
}
