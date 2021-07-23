
//Sleepy as Hell.
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b;
  for (int &i : a) {
    cin >> i;
  }
  for (int i = 1; i < n; i++) {
    b.push_back(a[i] - a[i - 1]);
  }
  b.push_back(b.back());
  int maxi = 0;
  vector<int> lef(n), rig(n + 1);
  lef[0] = 1;
  b.push_back(a[1] - a[0]);
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] == b.back()) {
      lef[i] = lef[i - 1] + 1;
      maxi = max(maxi, lef[i]);
    } else {
      lef[i] = 1;
      b.push_back(a[i] - a[i - 1]);
    }
  }
  if (maxi != n) maxi++;
  rig[n] = 0;
  b.clear();
  b.push_back(a[n - 1] - a[n - 2]);
  for (int i = n - 2; i >= 0; i--) {
    if (a[i + 1] - a[i] == b.back()) {
      rig[i] = rig[i + 1] + 1;
    } else {
      rig[i] = 1;
      b.push_back(a[i + 1] - a[i]);
    }
  }
  b.clear();
  b.push_back(a[n - 1] - a[n - 2]);
  for (int i = n - 2; i > 0; i--) {
    if (a[i + 1
    maxi = max(maxi, lef[i - 1] + rig[i + 1] + 1);
  }
  cout << maxi << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


