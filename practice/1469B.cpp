
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int m; cin >> m;
  vector<int> b(m);
  for (int &i : b) cin >> i;
  int maxia = 0, maxib = 0;
  int curr = maxia;
  for (int i = 0; i < n; i++) {
    curr += a[i];
    maxia = max(maxia, curr);
  }
  curr = 0;
  for (int i = 0; i < m; i++) {
    curr += b[i];
    maxib = max(maxib, curr);
  }
  cout << max(0, maxia + maxib) << '\n';
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


