
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int ans = 0;
  set<int> st;
  for (int i = 0; i < n; i++) {
    int maxi = 0;
    int mini = 0;
    for (int j = i; j < n; j++) {
      if (a[j] > maxi) {
        mini = maxi;
        maxi = a[j];
      } else if (a[j] > mini) {
        mini = a[j];
      }
      if (j - i + 1 >= 2)
        st.insert(maxi - mini);
    }
  }
  cout << st.size() << '\n';
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


