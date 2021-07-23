
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> pre(n, 0);
  pre[0] = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == '#') {
      pre[i] = pre[i - 1];
    } else {
      pre[i] = i;
    }
  }

  bool ok = true;
  for (int i = 0; i < n;) {
    int next = min(i + k, n - 1);
    if (next == n - 1) break;
    if (i == pre[next]) {
      ok = false;
      break;
    }
    i = pre[next];
  }
  cout << (ok ? "YES" : "NO") << '\n';
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


