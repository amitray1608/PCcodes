
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, a, y, x;
  cin >> n >> a >> x >> y;
  int res = 0;
  if (n <= a) res = n * x;
  else res = (n - a) * y + (a * x);
  cout << res << '\n';
  return 0;
} //Hajimemashite

