
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  set<int> st;
  vector<int> a(n), f(101, 0);
  for (int &i : a) {
    cin >> i;
    st.insert(i);
    f[i]++;
  }
  int maxi = *max_element(a.begin(), a.end());
  int mex = 0;
  for (int i = 0; i <= maxi; i++) {
    if (f[i] == 0) {
      mex = i;
      break;
    }
  }
  sort(a.begin(), a.end());
  for (int i : st) {
    if (i > mex) break;
    cout << i << ' ';
    f[i]--;
  }
  for (int i = 0; i <= maxi; i++) {
    while (f[i]--) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


