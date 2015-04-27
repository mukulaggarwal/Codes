#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int visited[102]={0};
int main()
{
    int n,m,i,j;
    char str[102],a[102];
    scanf("%d%d",&n,&m);
    int counter=0;
    for(i=0;i<n;i++)
    {
        scanf("%s",&str);
        int flag=1,k;
        for(j=0;j<m;j++)
        {
            if(i==0)
            {
                a[j]=str[j];
            }
            else
            {
                if(a[j]>str[j]&&visited[j]==0)
                {
                    cout<<"1st\n";
                    cout<<j<<endl;
                    counter++;
                    visited[j]=1;
                }
                else if(a[j]<str[j])
                {
                    cout<<"2nd\n";
                    a[j]=str[j];
                }
                else if(a[j]==str[j])
                {
                    cout<<"3rd\n";
                    if(visited[j]==0)
                    {
                    for(k=j+1;k<m;k++)
                    {
                        if(a[k]<str[k]&&visited[k]==0)
                        {
                            flag=1;
                            visited[k]=1;
                            break;
                        }
                        else if(a[k]>str[k])
                        {
                            flag=0;
                        }
                    }
                    if(flag==1)
                    {
                        cout<<"flag\n";
                        counter++;
                    }
                    }
                }

            }
        }
    }
    printf("%d\n",counter);
    return 0;
}


