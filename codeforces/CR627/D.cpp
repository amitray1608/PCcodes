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
	    int n;
	    cin >> n;
	    vector<ll> diff;
	    for(int i=0;i<n;i++){
	        ll x;
            cin >> x;
	        diff.push_back(x);
	    }
	    for(int i = 0; i<n; i++){
	        ll x;
            cin >> x;
	        diff[i] -= x;
	    }
	    sort(diff.begin(), diff.end());
	    ll maxi = 0;
	    for(int i = 0; i < n; i++){
			ll x = -diff[i];
            int pos = upper_bound(diff.begin()+i+1, diff.end(), x) - diff.begin();
	        maxi += n - pos;
	    }
	    cout << maxi << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
