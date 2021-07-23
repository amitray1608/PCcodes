
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
    bool neg = false;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      neg |= (x < 0);
    }
    if (neg) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    cout << 101 << '\n';
    for (int i = 0; i < 101; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  }	
  return 0;
} //Hajimemashite

