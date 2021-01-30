#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> pre0(n, 0), suff0(n, 0);
  vector<int> pre1(n, 0), suff1(n, 0);
  pre0[0] = (s[0] == '0');
  pre1[0] = (s[0] == '1');
  for (int i = 1; i < n; i++) {
    pre0[i] = pre0[i - 1] + (s[i] == '0');
    pre1[i] = pre1[i - 1] + (s[i] == '1');
  }

  suff0[n - 1] = (s[n - 1] == '0');
  suff1[n - 1] = (s[n - 1] == '1');
  for (int i = n - 2; i >= 0; i--) {
    suff0[i] = suff0[i + 1] + (s[i] == '0');
    suff1[i] = suff1[i + 1] + (s[i] == '1');
  }
  
  int mini = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
   int count = pre1[i] + suff0[i + 1];
   mini = min(mini, count);
  }
  for (int i = 1; i < n; i++) {
   int count = pre1[i - 1] + suff0[i];
   mini = min(mini, count);
  }
  mini = min(mini, n - suff1[0]);
  mini = min(mini, n - pre0[n - 1]);
  cout << mini << '\n';
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


