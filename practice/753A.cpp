
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> res;
  int k = 1;
  while (n >= k) {
    res.push_back(k);
    n -= k;
    k++;
  }
  res.back() += n;
  cout << res.size() << '\n';
  for (int i : res) 
    cout << i << ' ';
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


