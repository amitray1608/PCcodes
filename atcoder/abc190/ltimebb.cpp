#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int count = 0, maxi = -1;
  for (int &i : a) {
    cin >> i;
    count += (i != -1);
    maxi = max(maxi, i);
  }
  if (count < (n + 1) / 2) {
    cout << "Rejected" << '\n';
  } else if (maxi > k) {
    cout << "Too Slow" << '\n';
  } else if (count == n and maxi <= 1) {
    cout << "Bot" << '\n';
  } else {
    cout << "Accepted" << '\n';
  }
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


