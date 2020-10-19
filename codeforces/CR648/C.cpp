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
    ll a[n], b[n], c[n+1];
    map<ll, ll> m;
    for(ll &i : a) cin >> i;
    int j = 0;
    for(ll &i : b){
        cin >> i;
        c[i] = j++;
    }
    for(int i = 0; i < n; i++){
        ll f = i-c[a[i]];
        f = (f+n)%n;
        m[f]++;
    }
    ll maxi = 0;
    for(auto p : m){
        if(p.second > maxi)
            maxi = p.second;
    }
    cout << maxi << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		//cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
