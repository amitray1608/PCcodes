#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n);
#define PI acos(-1.0)
#define sl(n) scanf("%lld",&n);
#define sf(n) scanf("%lf",&n);
#define ss(n) scanf("%s",n);
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define forc(i,j,n) for(ll i=j;i<n;i++)
#define pb push_back
#define sor(n) sort(n.begin(),n.end())
#define sorcmp(n) sort(n.begin(),n.end(),cmp)
#define rev(n) reverse(n.begin(),n.end())
#define pi(x)  prllf("%d",x);
#define pl(x)  prllf("%lld",x);
#define pf(x)  prllf("%.10lf",x);
#define ps(x)  prllf("%s",x);
#define en() prllf("\n");
#define random_shuffle(r...)random_shuffle(r,[](int _){return rand()%_;})
#define SQR(a) (a)*(a)
#define mod 100000007
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
ll powmod(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod;a = a*a%mod;b >>= 1;}return ans;}
//ll prime[1000000];bool visprime[10000000];
//void sieve(){ll k=0;for(ll i=2;i*i<=1000000;i++){for(ll j=i*i;j<=1000000;j+=i){visprime[j]=true;}}for(ll i=2;i<=1000000;i++){if(visprime[i]==false) prime[k++]=i;}}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string x;
        cin>>x;
        if(n==1)
        {
            cout<<x<<endl<<1<<endl;
            continue;
        }
        int c=INT_MAX;

        for(int i=0;i<n;i++)
        {
            int p=x[i];
            if(p<c)
                c=p;
        }
       // cout<<(char)c<<endl;
        vector<int>v,temp;
          for(int i=0;i<n;i++)
        {
            int p=x[i];
            if(p==c)
               v.pb(i);
        }
     vector<int>mp[50005];
   int st=0;
        if(v[0]==0)
        {
            int p=x[1];
            temp.pb(p);
            mp[p].pb(0);
            st++;
        }

        for(int i=st;i<v.size();i++)
        {
            int ok= x[v[i]-1];
            temp.pb(ok);
            mp[ok].pb(v[i]);
        }

        for(int i=0;i<=5001;i++)
             sor(mp[i]);

      int mn=INT_MAX;
      int indx;
      sor(temp);
      indx=mp[temp[0]][0];
      int k=0;

       for(int i=0;i<n-indx;i++)
       {
          reverse(x.begin()+k,x.begin()+indx+i+1);
          k++;
       }
       cout<<x<<endl;
       cout<<indx+1<<endl;





    }











return 0;
}
