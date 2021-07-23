
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) 
    cin >> i;
  for (int i = 0; i < n / 2; i++) {
    if (~ i & 1) swap(a[i], a[n - i - 1]);
  }
  for (int i = 0; i < n; i++) 
    cout << a[i] << ' ';
  cout << '\n';
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


