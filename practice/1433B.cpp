
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int first = -1, last = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    if (x  and first == -1)
      first = i;
    if (x) last = i;
  }
  int count = 0;
  for (int i = first; i <= last; i++)
    if (!a[i]) count++;
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


