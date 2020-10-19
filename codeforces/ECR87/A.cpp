//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
// #define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for(ll &i : a) cin >> i;
	ll count = 0, ans = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i] == k) {
            count = 1;
            while(i < n-1 && a[i+1]+1 == a[i]) {
                i++;
                count++;
            }
            if(count >= k)
				ans++;
        }
	}
      cout << ans << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 0;
		cin >> t;
		for(int i = 1; i <= t; i++){
			cout << "Case #" << i <<": ";
			solve();
		}
	return 0;
}	
