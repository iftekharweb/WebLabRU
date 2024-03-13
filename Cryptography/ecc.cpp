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

vector<pair<int,int>> generate_subgroup(int px, int py, int a, int p)
{
    vector<pair<int,int>> G;
    G.push_back({px,py});

    //2G using point doubling operation
    int s=((3*px*px+a)%p)*bexpm(2*py,p-2,p)%p;
    int xig=(s*s-2*px)%p;
    int yig=(s*(px-xig)-py)%p;
    xig=(xig+p)%p; yig=(yig+p)%p;
    G.push_back({xig,yig});

    // //calculating 3G,4G,.... using point addition method
    for(int i=1; ;i++)
    {
        if(G[i].first==G[0].first)break;

        s=((G[i].second-G[0].second)%p)*bexpm(G[i].first-G[0].first,p-2,p)%p;
        xig=(s*s-G[0].first-G[i].first)%p;
        yig=(s*(G[0].first-xig)-G[0].second)%p;
        xig=(xig+p)%p; yig=(yig+p)%p;
        G.push_back({xig,yig});
    }
    return G;
}

int main()
{
    int p=19; // input
    int a=2; // input
    int b=5; // input

    cout<<"p = "<<p<<", a = "<<a<<", b = "<<b<<'\n';

    //affine points
    vector<int> px,py;
    cout<<"\nAffine points:\n";
    for(int x=0; x<p; x++)
    {
        for(int y=0; y<p; y++)
        {
            if((y*y)%p==(x*x*x+a*x+b)%p)
            {
                cout<<x<<" "<<y<<'\n';
                px.push_back(x);
                py.push_back(y);
            }
        }
    }

    // For each affine points generate subgroup

    vector<vector<pair<int,int>>> G(px.size());
    for(int i=0; i<px.size(); i++)
    {
        G[i]=generate_subgroup(px[i],py[i],a,p);
        cout<<"\nGenerator Point: ("<<G[i][0].first<<","<<G[i][0].second<<")\n";
        cout<<"\nSubgroup:\n";
        for(int j=0; j<G[i].size(); j++)cout<<G[i][j].first<<" "<<G[i][j].second<<'\n';
        cout<<"\nvalue of N: "<<G[i].size()<<'\n';
    }
    
    int ind=0;                                // index of affine point used as G
    int alpha=1, beta=2;                      // given or input or your choice; alpha,beta<G[ind].size
    int Pax=G[ind][alpha-1].first, Pay=G[ind][alpha-1].second;
    int Pbx=G[ind][alpha-1].first, Pby=G[ind][alpha-1].second;

    vector<pair<int,int>> sub;
    sub=generate_subgroup(Pax,Pay,a,p);
    int kx=sub[beta-1].first, ky=sub[beta-1].second;
    cout<<"Secret key (k): ";
    cout<<kx<<" "<<ky<<endl;
}