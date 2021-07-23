
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
    int o = 0, e = 0;
    for (int i = 0; i < 2 * n; i++) {
      int x;
      cin >> x;
      if (x & 1) o++;
      else e++;
    }
    bool ok = e == o;
    cout << (ok ? "Yes" : "No") << '\n';
  }	
  return 0;
} //Hajimemashite

