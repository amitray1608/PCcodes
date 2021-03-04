
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), vis(n + 2, 0);
  while (q--) {
    int l, r;
    cin >> l >> r;
    vis[l] += 1;
    vis[r + 1] -= 1;
  }
  for (int i = 1; i <= n; i++) {
    vis[i] += vis[i - 1];
  } 
  for (int i = 1; i <= n; i++) {
    if (vis[i] != 0) {
      cout << i << ' ';
    } else {
      cout << 1 << ' ';
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, p;
  cin >> t >> p;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


