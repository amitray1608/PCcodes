
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> ans = {9, 98, 989};
  if(n <= 3) cout << ans[n - 1];
  else {
    cout << ans[2];
    int i = 3, curr = 0;
    while(i < n) {
      i++;
      cout << curr;
      curr = (curr + 1) % 10;
    }
  }
  cout << "\n";
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

