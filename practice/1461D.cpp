#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define mp make_pair

const ll mod=1000000007;
const ll INF=1e18;

bool comp(int a, int b, vector<int> &v){
	return v[a]<v[b];
}

ll binpow(ll a, ll b) {
	a %= mod;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
void solve(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	int sortedfrom=-1;
	for (int i=n-1;i>=0;--i){
		if (a[i]!=i+1){
			sortedfrom=i;
		}
	}
	ld ans=0;
	for (int i = 0; i < m; ++i)
	{
		int r;ld p;
		cin>>r>>p;
		--r;
		if (r>=sortedfrom-1){
			ans=ans+(1-ans)*p;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--)
		solve();
	return 0;
}
