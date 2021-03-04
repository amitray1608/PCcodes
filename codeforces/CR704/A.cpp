#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll p;
  vector<ll> a(3);
  cin >> p >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  ll resa = p / a[0] + (p % a[0] != 0);
  resa *= a[0];
  resa -= p;
  ll resb = p / a[1] + (p % a[1] != 0);
  resb *= a[1];
  resb -= p;
  ll resc = p / a[2] + (p % a[2] != 0);
  resc *= a[2];
  resc -= p;
  cout << min({resa, resb, resc}) << '\n';
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


