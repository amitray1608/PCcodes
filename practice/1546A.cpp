
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int suma = 0, sumb = 0;
    for (int &i : a) cin >> i, suma += i;
    for (int &i : b) cin >> i, sumb += i;
    if (suma != sumb) {
      cout << -1 << '\n';
      continue;
    }
    vector<pair<int, int>> res;
    for (int j = 0; j < n; j++) {
      if (a[j] > b[j]) {
        int left = a[j] - b[j];
        a[j] = b[j];
        for (int k = 0; k < n; k++) {
          if (a[k] < b[k]) {
            while (left > 0 and a[k] < b[k]) {
              a[k]++, left--;
              res.push_back({j, k});
            }
          }
        }
      }
    }
    cout << res.size() << '\n';
    for (auto i : res) {
      cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
  }	
  return 0;
} //Hajimemashite

