#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,u,v;
ll bac[1000000];
ll par[1000000];
map<ll,vector<ll>> m;
ll a[500010][2];
bool vis[1000000];
void foo(int p)
{
    if(vis[p])
    return ;
    vis[p]=true;
    vector<ll> v=m[p];
    for(auto i:v)
    {
        if(par[i]==0)
        par[i]=p;
        foo(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    memset(vis,0,sizeof(vis));
    memset(par,0,sizeof(par));
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        m[u].push_back(v);
        m[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>bac[i];
    }
    foo(1);
    par[1]=0;
    for(int i=1;i<=n;i++)
    cout<<par[i]<<" ";
    cout<<endl;
    char ch;
    ll f,g;
    while(q--)
    {
        for(int i=n;i>1;i--)
        {
            if(m[i].size()==1)
            {
                bac[i]+=bac[par[i]];
            }
            else
            {
                bac[i]=bac[par[i]];
            }
        }
        bac[1]=0;
        cin>>ch;
        if(ch=='?')
        {
            cin>>f;
            cout<<bac[f]<<"\n";
        }
        else
        {
            cin>>f>>g;
            bac[f]+=g;
        }
        for(int i=1;i<=n;i++)
        cout<<bac[i]<<" ";
        cout<<endl;
    }
}

/*
1
8 25
1 2 3 4 5 6 7 8
*/
