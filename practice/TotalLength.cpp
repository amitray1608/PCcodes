#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0, curr = 0, j = 0;
  for (int i = 0; i < n; i++) {
    curr += a[i];
    while (curr > s) {
      curr -= a[j++];
    }
    int x = i - j + 1;
    if (curr <= s) ans += (x * (x + 1)) / 2;
  }
  cout << ans << '\n';
  
  return 0;
} //Hajimemashite
