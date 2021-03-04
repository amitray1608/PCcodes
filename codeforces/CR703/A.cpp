#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  long long total = 0;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
    long long acc = (i * (i + 1)) / 2;
    if (total < acc) ok = false;
  }
  cout << (ok ? "YES" : "NO") << "\n";
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


