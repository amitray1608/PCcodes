
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll &i : a) cin >> i;
  sort(a .begin(), a .end());
  
	ll sum = 0, sum2 = 0;
	for(ll i = 0; i < n; i++) {
		sum += a[i] * a[i];
		sum2 += a[i];
	}
	ll res = 0;
	for(int i = n - 1;i >= 0; i--){
		sum2 -= a[i];
		sum -= a[i] * a[i];
		res += (a[i] * a[i]) * i + sum - 2LL * a[i] * sum2;
	}
	cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


