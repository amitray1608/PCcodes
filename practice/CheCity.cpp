#include<bits/stdc++.h>

using namespace std;
#define int int64_t
#define deb(x) cout << #x << " = " << x << endl;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, r;
  cin >> n >> r;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0, j = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    while (j < i and x - a[j] > r) j++;
    if (j and x - a[j - 1] > r) ans += j;
  }
  cout << ans << '\n';

  return 0;
} //Hajimemashite
