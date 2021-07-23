
/*
	katana_handler
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set_pll tree <pll, null_type,greater<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree <ld, null_type,greater<ld>, rb_tree_tag,tree_order_statistics_node_update>
/*
 * query 1 order_of_key (k) : Number of items strictly smaller than k .
 * query 2 find_by_order(k) : K-th element in the set (counting from zero).
 * less<ll> means query 1 will return numbers strictly less than k
 * greater<ll> means query 1 will return numbers strictly greater than k
*/
#define			pb            	push_back
#define			pf              push_front
#define         MOD             1000000007
#define			popb            pop_back
#define         popf            pop_front
#define         len(x)          (ll)x.size()    
#define         MAXN            100001
#define         mp              make_pair
#define         endl            '\n'
#define         ff              first
#define         ss              second
#define         tt              third
#define         mapcl           map<char,ll>
#define         mapll           map<ll,ll>
#define         cmp             complex<double>
#define         pi              3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define         inf             LLONG_MAX
#define         flush           fflush(stdout)
#define         vll             vector<ll>
#define         all(v)          v.begin(),v.end()
#define         fr(i,z,n)       for(ll i=z;i<n;i++)
#define         sqrt            sqrtl
#define         cbrt            cbrtl
typedef         long long       ll;
typedef         pair<ll,ll>     pll;
typedef         long double     ld;
typedef			unsigned long long ull;
ll              power(ll a,ll b,ll mod)         {if(b==0)return 1;ll tmp=power(a,b/2,mod);tmp=(tmp*tmp)%mod;if(b&1)tmp=(tmp*a)%mod;return tmp;}
ll              mandist(pll a,pll b)            {return abs(a.ff-b.ff)+abs(a.ss-b.ss);}
ld             	dist2d(pll a,pll b)             {ll x=abs(a.ff-b.ff);ll y=abs(a.ss-b.ss);return (sqrt((x*x)+(y*y)));}
bool        	coll(pll p1,pll p2,pll p3)      {if((p3.ss-p2.ss)*(p2.ff-p1.ff)==(p2.ss-p1.ss)*(p3.ff-p2.ff))return true;else return false;}
void        	print(auto x)                   {cout<<x<<endl;}
void        	pv(vector<auto> v)              {for(ll i=0;i<(ll)v.size();i++)cout<<v[i]<<" ";cout<<endl;}
void        	pv1(vector<auto> v)             {for(ll i=1;i<(ll)v.size();i++)cout<<v[i]<<" ";cout<<endl;}
void        	pset(set<auto> v)               {for(auto x:v)cout<<x<<" ";cout<<endl;}
void        	pvsl(vector<auto> v)            {for(ll i=0;i<(ll)v.size();i++)cout<<v[i]<<" ";}
void        	in(vector<auto> &v, ll n)       {v.resize(n);for(ll i=0;i<n;i++)cin>>v[i];}
void        	in1(vector<auto> &v, ll n)      {v.resize(n+1);for(ll i=1;i<=n;i++)cin>>v[i];}
void        	sorta(auto &v)                  {sort(v.begin(),v.end());}
void        	sortd(auto &v)                  {sort(v.begin(),v.end(),greater <>());}		
void        	fast()                          {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
//all variables and functions below this line
vector< ull > BFS(ll n,ll start, vector< vector<pll> > &v)
{
	vector<ull> dist(n+1,0);
	queue<pair<ll,ull>> q;
	q.push(mp(start,0));
	vector<ll> vis(n+1,0);
	vis[start]=1;
	while(!q.empty())
	{
		pair<ll,ull> tmp=q.front();
		q.pop();
		dist[tmp.ff]=tmp.ss;
		for(pll x:v[tmp.ff])
		{
			if(!vis[x.ss])
			{
				vis[x.ss]=1;
				q.push(mp(x.ss,x.ff+tmp.ss));
			}
		}
	}
	return dist;
}
ll globalsum=0;
void solve()
{
	ll n;
	cin>>n;
	globalsum+=n;
	//assert(n<=1000 && n>=2);
	ull a[n+1][n+1];
	vector< vector<pll> > v(n+1);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			cin>>a[i][j];
			//assert(a[i][j]>=0 && a[i][j]<=1e18);
			if(i!=j)
			v[i].pb(mp(a[i][j],j));
		}
	}
	set<ll> s;
	s.insert(1);
	vll vis(n+1,0);
	vis[1]=1;
	priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> q;
	for(pll x:v[1])
	{
		q.push({x.ff,{1,x.ss}});
	}
	vector< vector<pll> > MST(n+1); 
	while(!q.empty())
	{
		ll U=q.top().ss.ff;
		ll V=q.top().ss.ss;
		ll W=q.top().ff;
		q.pop();
		if(vis[V])
		continue;
		vis[V]=1;
		MST[U].pb(mp(W,V));
		MST[V].pb(mp(W,U));
		for(pll x: v[V])
		{
			q.push({x.ff,{V,x.ss}});
		}
	}
	ll flag=1;
	for(ll i=1;i<=n;i++)
	{
		vector< ull > dist = BFS(n,i,MST);
		for(ll j=1;j<=n;j++)
		{
			if(dist[j]!=a[i][j])
			{
				flag=0;
				break;
			}
		}
	}
	cout<<flag<<endl;
	if(flag)
	{
		vector<pair<pll,ll>> ans;
		for(ll i=1;i<=n;i++)
		{
			for(pll x:MST[i])
			ans.pb(mp(mp(i,x.ss),x.ff));
		}
		for(auto x:ans)
		if(x.ff.ff<x.ff.ss)
		cout<<x.ff.ff<<" "<<x.ff.ss<<" "<<x.ss<<endl;
	}
}
int main()
{
	srand(time(NULL));
	fast();
	ll t=1;
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
		//cerr<<t<<endl;
		//cout<<"Case #"<<i<<": ";
		solve();
	}
	//assert(globalsum<=1000);
}
