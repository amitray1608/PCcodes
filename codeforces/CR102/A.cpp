
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  sort(a.begin(), a.end());
  bool flag = false;
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] <= d) count++;
  }
  if(count == n) flag = true;
  if(n == 1) {
    if(a[0] <= d) flag = true;
  } else if(n == 2) {
    if(a[0] <= d and a[1] <= d) flag = true;
  } else {
    if(a[0] + a[1] <= d) flag = true;
  }
  cout << (flag ? "YES" : "NO") << '\n';
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

