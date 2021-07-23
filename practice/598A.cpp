
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define deb(x) cout << #x << " = " << x << endl;


void solve() {
  ll n;
  cin >> n;
  ll x = (ll)log2(n);
  ll twos = (1LL << (x + 1LL)) - 1LL;
  ll sum = (n * (n + 1LL)) / 2LL;
  ll res = sum - 2LL * twos;
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


