#include<cstdio>
#include<iostream>
#include<cmath>
#include<set>
#include<iterator>
#include<cstdlib>
#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

set<int> ss;
set<int>::iterator it;
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}

// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int n)
{
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));

        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
                //printf("%d ", i+1);
                ss.insert(i+1);
                markMultiples(arr, i+1, n);
            }
        }
    }
}

int main()
{
    int i,n,j;
    int prime[MAX+1];
    SieveOfEratosthenes(MAX);
    for(i=4;i<=MAX;i++)
    {
        prime[i]=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
                prime[i]+=i/j-1;
        }
        prime[i]++;
    }
    prime[1]=0;
    prime[2]=1;
    prime[3]=2;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(ss.find(prime[n])!=ss.end())
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }
    return 0;
}
