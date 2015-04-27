#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> a(100),b(20);
    b[1]="one";
    b[2]="twenty";
    b[3]="thirty";
    b[4]="forty";
    b[5]="fifty";
    b[6]="sixty";
    b[7]="seventy";
    b[8]="eighty";
    b[9]="ninety";

    a[0]="zero";
    a[1]="one";
    a[2]="two";
    a[3]="three";
    a[4]="four";
    a[5]="five";
    a[6]="six";
    a[7]="seven";
    a[8]="eight";
    a[9]="nine";
    a[10]="ten";
    a[11]="eleven";
    a[12]="twelve";
    a[13]="thirteen";
    a[14]="fourteen";
    a[15]="fifteen";
    a[16]="sixteen";
    a[17]="seventeen";
    a[18]="eighteen";
    a[19]="nineteen";
    a[20]="twenty";
    int n;
    scanf("%d",&n);
    if(n==10)
        cout<<"ten\n";
    else if(n==20)
        cout<<"twenty\n";
    else if(n==30)
        cout<<"thirty\n";
    else if(n==40)
        cout<<"forty\n";
    else if(n==50)
        cout<<"fifty\n";
    else if(n==60)
        cout<<"sixty\n";
    else if(n==70)
        cout<<"seventy\n";
    else if(n==80)
        cout<<"eighty\n";
    else if(n==90)
        cout<<"ninety\n";
    else if(n/10&&n>20)
    {
        cout<<b[n/10]<<"-"<<a[n%10]<<endl;
    }
    else
    {
        cout<<a[n]<<endl;
    }
    return 0;
}
