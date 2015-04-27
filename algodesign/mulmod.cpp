#define MOD 1000000007
long long mulmod(long long a,long long b)
 {if(b==0)
   return 1;
   if(b==1)
    return a;
   long long x=mulmod(a,b/2);
   x=(x*x)%MOD;
   if(b%2)
     x=(x*a)%MOD;
    return x;
 }