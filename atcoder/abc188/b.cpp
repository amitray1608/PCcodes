#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for(int &i : a) cin >> i;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (a[i] * b[i]);
  }
  cout << (sum == 0 ? "Yes" : "No")  << '\n';
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

