//https://en.wikipedia.org/wiki/Primitive_root_modulo_n

#include<bits/stdc++.h>
using namespace std;

long long bexpm(long long  n, long long p, long long mod)
{
    long long res=1;
    n%=mod;
    while(p)
    {
        if(p&1)res=res*n%mod;
        p>>=1;
        n=n*n%mod;
    }
    return res;
}

int main()
{
    cout<<"Enter value of n: ";
    int n; cin>>n;

    set<int> coprime,tmp;
    for(int i=1; i<n; i++)
    {
        if(__gcd(i,n)==1)coprime.insert(i);
    }
   
    vector<int> primitive_roots;
    for(int x=2; x<n; x++)
    {
        tmp=coprime;
        for(int i=1; i<n; i++)
        {
            int val=bexpm(x,i,n);
            if(tmp.find(val)!=tmp.end())tmp.erase(val);
        }
        if(tmp.empty())primitive_roots.push_back(x);
    }
    cout<<"Primitive roots of n: ";
    for(int x:primitive_roots)cout<<x<<" ";
    cout<<endl;
}