#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;

int main()
{
    map<char,int> key,place;
    key['.']=1;
    key[',']=2;
    key['?']=3;
    key['!']=4;
    key['1']=5;

    key['a']=1;
    key['b']=2;
    key['c']=3;
    key['2']=4;

    key['d']=1;
    key['e']=2;
    key['f']=3;
    key['3']=4;

    key['g']=1;
    key['h']=2;
    key['i']=3;
    key['4']=4;

    key['j']=1;
    key['k']=2;
    key['l']=3;
    key['5']=4;

    key['m']=1;
    key['n']=2;
    key['o']=3;
    key['6']=4;

    key['p']=1;
    key['q']=2;
    key['r']=3;
    key['s']=4;
    key['7']=5;

    key['t']=1;
    key['u']=2;
    key['v']=3;
    key['8']=4;

    key['w']=1;
    key['x']=2;
    key['y']=3;
    key['z']=4;
    key['9']=5;

    key['0']=2;
    key['_']=1;

    place['.']=1;
    place[',']=1;
    place['?']=1;
    place['!']=1;
    place['1']=1;

    place['a']=2;
    place['b']=2;
    place['c']=2;
    place['2']=2;

    place['d']=3;
    place['e']=3;
    place['f']=3;
    place['3']=3;

    place['g']=4;
    place['h']=4;
    place['i']=4;
    place['4']=4;

    place['j']=5;
    place['k']=5;
    place['l']=5;
    place['5']=5;

    place['m']=6;
    place['n']=6;
    place['o']=6;
    place['6']=6;

    place['p']=7;
    place['q']=7;
    place['r']=7;
    place['s']=7;
    place['7']=7;

    place['t']=8;
    place['u']=8;
    place['v']=8;
    place['8']=8;

    place['w']=9;
    place['x']=9;
    place['y']=9;
    place['z']=9;
    place['9']=9;

    place['0']=0;
    place['_']=0;

    int t,i,sum=0;
    scanf("%d",&t);
    char str[10001];
    while(t--)
    {
        sum=0;
        int prev=1;
        scanf("%s",str);

        int sz=strlen(str);
        for(i=0;i<sz;i++)
        {
            if(place[str[i]]==prev)
            {
                sum+=key[str[i]];
                //cout<<sum<<' '<<key[str[i]]<<' '<<str[i]<<endl;
            }
            else
            {
                sum+=key[str[i]]+1;
                prev=place[str[i]];
                //cout<<sum<<' '<<key[str[i]]<<endl;
            }
        }
        printf("%d\n",sum);
    }
}
