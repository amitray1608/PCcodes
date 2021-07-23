
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, m, px, py;
    cin >> n >> m >> px >> py;
    vector<array<int, 2>> a = {
      {1, 1}, {n, 1}, {1, m}, {n, m}
    };
    int maxi = -1;
    pair<int, int> res[2];
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int req = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
        if (req > maxi) {
          maxi = max(maxi, req);
          res[0].first = a[i][0];
          res[0].second = a[i][1];
          res[1].first = a[j][0];
          res[1].second = a[j][1];
        }
      }
    }
    for (int i = 0; i < 2; i++) {
      auto j = res[i];  
      cout << j.first << ' ' << j.second << ' ';
    } cout << '\n';

  }	
  return 0;
} //Hajimemashite

