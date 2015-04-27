#include<bits/stdc++.h>
using namespace std;

//n-> size of pattern
//m-> size of text

char *pat;
char *text;
vector<int> kmp;
void pattern(int n)
{
    int i=1,len=0;
    kmp.push_back(0);
    for(i=0;i<=n;i++)
        kmp.push_back(0);
    i=1;
    while(i<n)
    {
       if(pat[i]==pat[len])
       {
           len++;
           kmp[i]=len;
           i++;
       }
       else
       {
           if(len!=0)
            len=kmp[len-1];
           else
           {
               kmp[i]=0;
               i++;
           }
       }
    }
}

void knuth(int n,int m)
{
    int i=0,j=0;
    while(i<m)
    {
        if(pat[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==n)
        {
            cout<<"pattern found at "<<i-j<<endl;
            j=kmp[j-1];
        }
        else if(i<m&&pat[j]!=text[i])
        {
            if(j==0)
            {
                i++;
            }
            else
                j=kmp[j-1];
        }
    }
}
int main()
{
    pat="AA";
    text="AAAA";
    int n=strlen(pat);
    int m=strlen(text);
    pattern(n);
    knuth(n,m);
    return 0;
}
