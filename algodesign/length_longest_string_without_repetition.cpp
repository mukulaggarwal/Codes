#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char x[100000];
    cin>>x;
    int i,prev,current=1,maxlength=1,start=0,end=0,new_start=0,new_end=0;
    int visited[256];
    for(i=0;i<256;i++)
        visited[i]=-1;
    visited[x[0]]=0;
    for(i=1;i<strlen(x);i++)
    {
        prev=visited[x[i]];
        if(prev==-1||i-current>prev)
        {
            current++;
            //cout<<new_end-new_start<<" "<<end-start<<endl;
            if(new_end-new_start>=end-start&&new_end-new_start!=0)
            {
                start=new_start;
                end=new_end;
                //cout<<"in "<<start<<" "<<end<<endl;
            }
            else
            {
                start=new_start;
                end=i;
            }
        }
        else
        {
            if(maxlength<current)
            {
                maxlength=current;
            }
            current=i-prev;
            new_start=prev+1;
            new_end=i;
        }
        visited[x[i]]=i;
    }
    cout<<"maximum length is "<<max(current,maxlength)<<endl;
    if(new_end-new_start>=end-start)
            {
                start=new_start;
                end=new_end;
            }
    //for(i=start;i<=end;i++)
     //   cout<<x[i]<<" ";
    return 0;

}
