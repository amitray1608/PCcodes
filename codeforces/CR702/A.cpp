#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  std::vector<int> a(n);
  for (int &i : a) cin >> i;
  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    int mini = min(a[i], a[i + 1]);
    int maxi = max(a[i], a[i + 1]);
    if (maxi > mini * 2) {
      for (;mini < maxi;) {
        mini *= 2;
        count++;
      }
      count--;
    }
  } 
  cout << count << '\n';
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


