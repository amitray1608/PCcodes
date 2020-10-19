//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>>v(n);
	ll vis[m] = {0};
	for(ll i = 0; i <n; i++) cin >> v[i].first;
	ll j = m-1, k = 0;
		
	for(ll i = 0; i<n; i++) {
		v[i].second = k;
		k++;
		if(k == m) k = 0;
	}
	//map<ll, ll>check;
	//sort(v.begin(), v.end());
	set<ll>s;
	ll p[m] = {0};
		for(ll i = n-1; i >= 0; i--){
		if(p[v[i].second] == 0 && j >= 0){
			vis[v[i].second] = v[i].first;
			j--;
			p[v[i].second] = 1;
			//check[v[i].second] = j;
		}
	}
	ll mini = *min_element(vis, vis+m), maxi = *max_element(vis, vis+m);
		ll ans = abs(maxi -  mini);
	for(ll i = n-1; i>=0; i--){
		ll x = v[i].first, pos = v[i].second;
		//ll y = check[pos];
			vis[pos] = x;
			maxi = *max_element(vis, vis+m);
			mini = *min_element(vis, vis+m);
		
		ans = min(ans, abs(maxi - mini));
	}
	
	cout << ans << endl;
}
/*
1
8 4
5 9 8 2 3 7 6 1
*/
int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
