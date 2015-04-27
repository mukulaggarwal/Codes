#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,m,j,flag,k;
    string X;
    string Y="CODEFORCES";
    cin>>X;
    size_t f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18;
    f1=X.find("C");
    f2=X.find("ODEFORCES");
    f3=X.find("CO");
    f4=X.find("DEFORCES");
    f5=X.find("COD");
    f6=X.find("EFORCES");
    f7=X.find("CODE");
    f8=X.find("FORCES");
    f9=X.find("CODEF");
    f10=X.find("ORCES");
    f11=X.find("CODEFO");
    f12=X.find("RCES");
    f13=X.find("CODEFOR");
    f14=X.find("CES");
    f15=X.find("CODEFORC");
    f16=X.find("ES");
    f17=X.find("CODEFORCE");
    f18=X.find("S");
    if(X.find("C")!=string::npos&&X.find("ODEFORCES")!=string::npos&&f1<f2)
    {
        printf("YES\n");
    }
    else if(X.find("CO")!=string::npos&&X.find("DEFORCES")!=string::npos&&f3<f4)
    {
        printf("YES\n");
    }
    else if(X.find("COD")!=string::npos&&X.find("EFORCES")!=string::npos&&f5<f6)
    {
        printf("YES\n");
    }
    else if(X.find("CODE")!=string::npos&&X.find("FORCES")!=string::npos&&f7<f8)
    {
        printf("YES\n");
    }
    else if(X.find("CODEF")!=string::npos&&X.find("ORCES")!=string::npos&&f9<f10)
    {
        printf("YES\n");
    }
    else if(X.find("CODEFO")!=string::npos&&X.find("RCES")!=string::npos&&f11<f12)
    {
        printf("YES\n");
    }
    else if(X.find("CODEFOR")!=string::npos&&X.find("CES")!=string::npos&&f13>f14)
    {
        printf("YES\n");
    }
    else if(X.find("CODEFORC")!=string::npos&&X.find("ES")!=string::npos&&f15<f16)
    {
        printf("YES\n");
    }
    else if(X.find("CODEFORCE")!=string::npos&&X.find("S")!=string::npos&&f17<f18)
    {
        printf("YES\n");
    }
    else if(X.find("CODEFORCES")!=string::npos)
    {
        printf("YES\n");
    }
    else
        printf("NO\n");
    return 0;
}
