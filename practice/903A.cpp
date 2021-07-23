
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    bool ok = false;
    for (int i = 0; i * 3 <= n; i++) {
      int x = i * 3;
      int left = n - x;
      if (left % 7 == 0) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  
  return 0;
} //Hajimemashite

