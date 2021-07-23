
#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, k;
    cin >> n >> k;
    long long res = 1;
    for (int i = 0; i < k; i++) {
      res = (res * n) % MOD;
    }
    cout << res << '\n';
  }

  return 0;
} //Hajimemashite

