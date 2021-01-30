
#include <bits/stdc++.h>

using namespace std;


void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> boy(k), girl(k);
  map<int, int> B, G;
  for(int &i : boy) cin >> i, B[i]++;
  for(int &i : girl) cin >> i, G[i]++;
  long long ans = 0;
  for(int i = 0; i < k; i++) {
    ans += (k - 1) - (B[boy[i]] - 1) - (G[girl[i]] - 1);
  }
  cout << ans/2 << '\n';
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

