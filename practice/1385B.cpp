
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int &i : a) cin >> i;
  vector<int> vis(n + 1, 0);
  for (int i : a) {
    if (!vis[i]) {
      cout << i << ' ';
      vis[i] = 1;
    }
  }
  cout << '\n';
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


