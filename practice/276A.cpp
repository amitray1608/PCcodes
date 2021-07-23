
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<array<int, 2>> a(n);
  for (auto &i : a) 
    cin >> i[0] >> i[1];
  int maxi = INT_MIN;
  for (auto i : a) {
    int ans = 0;
    if (i[1] > k) {
      ans = i[0] - (i[1] - k); 
    } else {
      ans = i[0];
    }
    maxi = max(ans, maxi);
  }
  cout << maxi << '\n';
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


