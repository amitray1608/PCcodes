
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
    bool ok = false;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (int(sqrt(x)) * int(sqrt(x)) != x) 
        ok = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
} //Hajimemashite

