
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int wina = max(a, b);
    int winb = max(c, d);
    bool ok = true;
    if (wina < min(c, d) or winb < min(a, b)) {
      ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  } 	
  return 0;
} //Hajimemashite

