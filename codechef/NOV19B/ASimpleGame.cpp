//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	ll n;
	cin >> n;
	vector<tuple<ll,ll, ll>>chef(n);
	//vector<pair<ll, ll>>rem(n);
	for(ll i  = 0; i<n; i++){
		ll s;
		cin >> s;
		ll a[s];
		for(ll &k : a) cin >> k; 
		ll sum = 0;
		for(ll j = 0; j < (s+1)/2; j++)
			sum += a[j];
			
		ll x = a[(s+1)/2 - 1];
		chef[i] = make_tuple(sum, s, x);
	}
	sort(chef.begin(), chef.end(), greater<>());
	ll sum = 0, turn = 0;
	for(auto i : chef){ tuple<ll, ll, ll>tp = i;
		ll s = get<0>(tp);
		ll siz = get<1>(tp);
		ll mid = get<2>(tp);
		if(turn == 0){
			sum += s;
			if(siz&1) turn = 1;
			else turn = 0;
		}else {
			sum += s;
			if(siz&1) turn = 0;	
			else turn = 1;
			
			if(siz&1) sum -= mid;
		}
		//cout << sum << endl;
		//cout << get<0>(tp) << " " << get<1>(tp) << " " << get<2>(tp) <<endl;
	}
	cout << sum << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
