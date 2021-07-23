
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n, k;
  cin >> n >> k;
  set<int> mexi;
  int mex, maxi = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mexi.insert(x);
    maxi = max(maxi, x);
  }
  mex = 0;
  for (auto i : mexi) {
    if (i != mex) break;
    mex++;
  }
  if (k == 0) {
    cout << mexi.size() << '\n';
    return;
  }
  int ans = 0;
  if (mex < maxi) {
    mexi.insert((mex + maxi + 1) / 2);
  } else {
    ans = k;
  }
  cout << mexi.size() + ans << '\n';
}

signed main() {
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


