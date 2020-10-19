#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
 
 
int main()
{
   int q,x;
   cin>>q>>x;
   ll a[x];
   for(int i=0;i<x;i++)
   a[i]=i;
   
   map<ll,ll> f;
   int ans=0;
	while(q--)
           ll y;
           cin>>y;
           y = y%x;
           f[a[y]]=1;
           a[y] = a[y]+x;
           while(f[ans] > 0) ans++;
           cout << ans << endl;
   }
}
