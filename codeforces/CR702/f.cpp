
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> st;
  int maxi = 0;
  map<int, int> mp;
  for (int &i : a) {
    cin >> i;
    mp[i]++;
    maxi = max(maxi, mp[i]);
    st.insert(i);
  }
  int res = n;
  auto check = [&](int x) {
    int count = 0;
    for (auto i : st) {
      if (mp[i] >= x) {
        count += mp[i] - x;
      } else 
        count += mp[i];
    }
    res = min(res, count);
    return count;
  };
  vector<int> curr(st.begin(), st.end());
  int l = 0, r = (int)st.size() - 1;
  while (l + 4 <= r) {
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;
    if (check(curr[mid1]) <= check(curr[mid2])) {
      l = mid1 + 1;
    } else {
      r = mid2 - 1;
    }
  }
  for (int i = l; i <= r; i++) 
    check(curr[i]);
  cout << res << '\n';
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


