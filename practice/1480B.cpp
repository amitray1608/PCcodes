
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int A, B;
  cin >> A >> B;
  int n;
  cin >> n;
  vector<array<int, 2>> monster(n);
  for (int i = 0; i < n; i++) {
    cin >> monster[i][0];
  }
  for (int i = 0; i < n; i++) {
    cin >> monster[i][1];
  }
  sort (monster.begin(), monster.end());


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


