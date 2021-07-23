
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, k;
    cin >> n >> k;
    int curr = 1;
    int count = 0;
    while (count <= min((int)20, n - 1)) {
      count++;
      cout << curr << endl;
      int inp;
      cin >> inp;
      curr *= 2;
      if (inp == 1) break;
      if (inp == 0) {
        continue;
      }
      exit(0);
    }
  }
  return 0;
} //Hajimemashite

