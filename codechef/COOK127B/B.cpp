
#include<bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long first = k + 2;
    long long last = first + (n + m - 2);
    long long res = 0;
    if (n != m) {
      res = first ^ last;
    } else {
      for (long long i = first; i <= last; i += 2) {
        res ^= i;
      }
    }
    cout << res << '\n';
  }
  return 0;
} //Hajimemashite

