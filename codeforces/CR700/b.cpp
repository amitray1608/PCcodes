

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll A, B, n;
  cin >> A >> B >> n;
  vector<pair<ll, ll>> X;
  vector<ll> hit(n), a(n);
  for (int i = 0; i < n; i++) {
    cin >> hit[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto check = [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
    return x.first < y.first;
  };

//  sort(a.begin(), a.end());
  bool ok = true;
  ll total = 0, pos = 0, i;
  for (i = 0; i < n; i++) {
    ll timesa = B / hit[i] + (B % hit[i] != 0);
    ll timesb = a[i] / A + (a[i] % A != 0);
    if (timesa < timesb) {
      ok = false;
      break;
    } else {
      B -= hit[i] * timesb;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


