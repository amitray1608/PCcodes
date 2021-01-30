#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;
  ll same = k;
  while(same < n) {
    same += k;
  }
  cout << (same % n == 0 ? (same / n) : (same / n + 1)) << '\n';
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


