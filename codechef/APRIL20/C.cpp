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
	ll n;
	cin >> n;
	ll a[n];
	for(ll &i : a) cin >> i;
	ll x = 2;
	ll total = (n*(n+1));
	total /= x;
	vector<pair<ll, ll>>v;
	for(ll i = -1; i <= n; i++){
		if(i == -1){
			v.push_back(make_pair(-1, 0));
		}else if(i == n){
			v.push_back(make_pair(n, 0));
		}else{
			x = 4;
			if(abs(a[i])%x == 0){
				v.push_back(make_pair(i, 0LL));
			}else if(abs(a[i])%x == 2){
				v.push_back(make_pair(i, 2LL));
			}
		}
	}
	//cout << total << endl;
	for(ll i = 1; i < (ll)v.size()-1; i++){
		if(v[i].second == 2){
			ll betw = v[i].first-v[i-1].first;
			betw *= v[i+1].first-v[i].first;
			total -= betw;
			//cout << betw << endl;
		}
	}
	cout << max(total, 0LL) << endl;
}

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
