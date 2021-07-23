
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    int xo = 0;
    vector<int> a(n), res(30);
    for (int &i : a) {
      cin >> i;
      xo ^= i;
    }
    int x = 0, y = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      x ^= a[i];
      if (x == xo) {
        x = 0;
        y++;
      }
    }
    if (xo == 0 or (x == 0 and y > 1)) {
      ok = true;
    } 
    cout << (ok ? "YES" : "NO") << "\n";
  }	
  return 0;
} //Hajimemashite

