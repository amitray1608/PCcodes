
#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<int> a(4);
  for (int i = 0; i < 4; i++) 
    cin >> a[i];
  sort (a.begin(), a.end());
  cout << a[0] * a[2] << '\n';
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


