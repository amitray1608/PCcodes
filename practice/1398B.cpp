
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int count = 0;
  vector<int> st;
  for (char c : s) {
    if (c == '1') count++;
    else {
      st.push_back(count);
      count = 0;
    }
  }
  if (count) st.push_back(count);
  sort(st.rbegin(), st.rend());
  int alice = 0;
  int n = st.size();
  for (int i = 0; i < n; i++) {
    if (~i&1) alice += st[i];
  }
  cout << alice << '\n';
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


