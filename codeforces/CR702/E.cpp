#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  map<int, int> mp;
  int j = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    a[i][1] = i;
    mp[i] = i;
  }
  sort (a.begin(), a.end());
  int l = 0, r = n - 1;
  int ans = n - 1;
  
  auto ok = [&](int x) {
    ll total = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (i <= x) { 
        total += a[i][0];
      } else {
        if (total < a[i][0])
          flag = false;
        else
          total += a[i][0];
      }
    }
    return flag;
  };

  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok (mid)) {
      r = mid - 1;
      ans = mid;
    } else l = mid + 1;
  }
  vector<int> pos;
  for (int i = ans; i < n; i++) {
    pos.push_back(a[i][1]);
  }
  sort(pos.begin(), pos.end());
  
  ans = n - ans;
  cout << ans << '\n';
  for (int i = 0; i < (int)pos.size(); i++) {
    cout << pos[i] + 1<< ' ';
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


