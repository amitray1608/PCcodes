
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  auto check = [&](int x) {
    set<int> st;
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
      mp[a[i]]++;
      st.insert(a[i]);
    }
    if (st.find(x) == st.end()) return true; 
    for (int i = m; i < n; i++) {
      mp[a[i]]++;
      st.insert(a[i]);
      int c = a[i - m];
      mp[c]--;
      if (mp[c] == 0) 
        st.erase(c); 
      if (*st.begin() > x) return true;
    }
    return false;
  };
  int l = 0, r = n;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l << '\n';
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


